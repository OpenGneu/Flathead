// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"
#include "Flathead.h"
#include "Interfaces/ConsoleInterfaces.h"
#include "Interfaces/ModuleInterfaces.h"

#include "Utility/ArrayBufferAllocator.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "v8.h"
#include "libplatform/libplatform.h"

using namespace Gneu;
using namespace Gneu::Utility;
using namespace Gneu::Interfaces;
using namespace v8;

Platform* g_Platform = NULL;
Isolate* g_CurrentVM = NULL;
Persistent<Context> g_GlobalContext;
Persistent<Function> g_Tick;

ArrayBufferAllocator g_ArrayBufferAllocator;

bool g_ICUInitialized = false;
bool g_Initialized = false;

#define INITIALIZE_SCOPE() \
Isolate::Scope isolate_scope(g_CurrentVM); \
HandleScope handle_scope(g_CurrentVM); \
Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext); \
Context::Scope context_scope(context); 

#define EXEC( _input ) \
Local<String> source = String::NewFromUtf8(g_CurrentVM, _input, NewStringType::kNormal).ToLocalChecked(); \
Local<Script> script = Script::Compile(context, source).ToLocalChecked(); \
Local<Value> result = script->Run(context).ToLocalChecked();

#define WHOLE_TOMATO( _input ) \
INITIALIZE_SCOPE(); \
EXEC(_input);

#define SetV8Flag( flag ) \
V8::SetFlagsFromString(flag, strlen(flag));

FH_API Flathead::Flathead()
{
	configuration = new Configuration();

	if (configuration->ShouldInitializeImmediately())
	{
		InitializeV8();
	}
}

FH_API Flathead::Flathead(Configuration &cfg)
{
	configuration = new Configuration(cfg);
	
	if (configuration->ShouldInitializeImmediately())
	{
		InitializeV8();
	}
}

FH_API Flathead::~Flathead()
{
	if (g_CurrentVM != NULL)
	{
		CleanupV8();
	}
}

FH_API Configuration * Flathead::GetConfiguration()
{
	return configuration;
}

FH_API void Flathead::InitializeV8()
{
	if (g_Initialized)
	{
		perror("Already Initialized");
		return;
	}

	g_Initialized = true;

	if (!V8::InitializeICU())
	{
		perror("Failed to initialize ICU");

		g_ICUInitialized = true;
		return;
	}

	if (g_Platform == NULL)
	{
		g_Platform = v8::platform::CreateDefaultPlatform();

		V8::InitializePlatform(g_Platform);
	}

	if (g_Platform == NULL)
	{
		perror("Failed to initialize the platform");
		return;
	}
	
	HandleV8Flags();

	if (!V8::Initialize())
	{
		perror("Failed to initialize V8 appropriately");
		return;
	}

	Isolate::CreateParams create_params;
	create_params.array_buffer_allocator = &g_ArrayBufferAllocator;

	g_CurrentVM = Isolate::New(create_params);

	if (g_CurrentVM == NULL)
	{
		perror("Failed to create a new VM");
	}

	InitializeGlobalContext();
	PreloadCore();
}

void Flathead::PreloadCore()
{
	Isolate::Scope isoScope(g_CurrentVM);
	HandleScope handScope(g_CurrentVM);
	TryCatch try_catch;

	try_catch.SetVerbose(true);

	Local<Context> context = Local<Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope conScope(context);

	if (GetConfiguration()->Bootstrap() != NULL)
	{
		FILE* file;

		if (fopen_s(&file, GetConfiguration()->Bootstrap(), "rb"))
		{
			throw 1;
			// perror("Could not load bootstrap file.");
			// return; 
		}

		fseek(file, 0, SEEK_END);

		int size = ftell(file);
		rewind(file);

		char* result = new char[size + 1];
		result[size] = '\0';
		int read = static_cast<int>(fread_s(result, size, 1, size, file));
		fclose(file);
		
		Local<String> name = String::NewFromUtf8(g_CurrentVM, GetConfiguration()->Bootstrap(), NewStringType::kNormal).ToLocalChecked();
		ScriptOrigin origin(name);
		Local<String> source = String::NewFromUtf8(g_CurrentVM, result, NewStringType::kNormal).ToLocalChecked();
		Local<Script> script = Script::Compile(context, source, &origin).ToLocalChecked();
		Local<Value> BSResult = script->Run(context).ToLocalChecked();

		if (BSResult.IsEmpty() || try_catch.HasCaught())
		{
			String::Utf8Value utf8(try_catch.Exception());
			perror(*utf8);
			return;
		}

		if (!BSResult->IsFunction())
		{
			perror("The bootstrap script is supposed to return a function with the following signature: \n");
			return;
		}

		Local<Function> func = Local<Function>::Cast(BSResult);

		if (func.IsEmpty())
		{
			perror("The bootstrap script is supposed to return a function with the following signature: \n");
			return;
		}

		Local<v8::Value> args[] = {
			Function::New(g_CurrentVM, &ConsoleInterfaces::Log, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ConsoleInterfaces::Info, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ConsoleInterfaces::Warn, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ConsoleInterfaces::Error, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ConsoleInterfaces::Assert, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ModuleInterfaces::Exists, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ModuleInterfaces::LoadModule, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ModuleInterfaces::Execute, External::New(g_CurrentVM, this)),
			Function::New(g_CurrentVM, &ModuleInterfaces::Modified, External::New(g_CurrentVM, this)),
			String::NewFromUtf8(g_CurrentVM, GetConfiguration()->Path()),
			String::NewFromUtf8(g_CurrentVM, V8::GetVersion()),
			String::NewFromUtf8(g_CurrentVM, BINDING_VERSION),
			Boolean::New(g_CurrentVM, GetConfiguration()->EnableHotReload()),
		};

		Local<Value> load = func->Call(context->Global(), sizeof(args) / sizeof(args[0]), args);

		if (try_catch.HasCaught())
		{
			String::Utf8Value utf8(try_catch.Exception());
			perror(*utf8);
			return;
		}

		// Provide place for bootstrap to return output
		if (!load.IsEmpty() && !load->IsUndefined())
		{
			if (load->IsFunction())
			{
				Handle<Function> func = Handle<Function>::Cast(load);
				g_Tick.Reset(g_CurrentVM, func);
			}
			else
			{
				String::Utf8Value utf8(load);
				printf("> %s", *utf8);
			}
		}

		printf("Bootstrap executed successfully.\n");
	}
}

void Flathead::InitializeGlobalContext()
{
	Isolate::Scope isolateScope(g_CurrentVM);
	HandleScope handleScope(g_CurrentVM);

	if (!g_GlobalContext.IsEmpty())
	{
		g_GlobalContext.Empty();
	}

	Handle<Context> ctxHandle = Context::New(g_CurrentVM, NULL, ObjectTemplate::New(g_CurrentVM));

	g_GlobalContext.Reset(g_CurrentVM, ctxHandle);
}

void Flathead::HandleV8Flags()
{
#ifdef _DEBUG
	// SetV8Flag("--debugger --expose_debug_as=v8debug");
#endif

	if (GetConfiguration()->AlwaysStrict())
	{
		SetV8Flag("--use_strict");
	}

	if (GetConfiguration()->EnableHarmony())
	{
		SetV8Flag("--harmony");
	}

	if (GetConfiguration()->EnableHarmonyDestructuring())
	{
		SetV8Flag("--harmony-destructuring");
	}

	if (GetConfiguration()->EnableHarmonyCollections())
	{
		SetV8Flag("--harmony_collections");
	}

	if (GetConfiguration()->EnableHarmonyTypeOf())
	{
		SetV8Flag("--harmony_typeof");
	}

	if (GetConfiguration()->EnableHarmonyScoping())
	{
		SetV8Flag("--harmony_scoping");
	}

	if (GetConfiguration()->EnableHarmonyProxies())
	{
		SetV8Flag("--harmony_proxies");
	}

	if (GetConfiguration()->EnableHarmonyModules())
	{
		SetV8Flag("--harmony_modules");
	}
}

FH_API void Flathead::CleanupV8()
{
	if (!g_Initialized)
	{
		return;
	}

	g_Initialized = false;

	g_GlobalContext.Reset();
	g_Tick.Reset();

	g_CurrentVM->Dispose();

	while (platform::PumpMessageLoop(g_Platform, g_CurrentVM))
	{
		continue;
	}
}

FH_API void Flathead::Execute(char *input, char *output)
{
	WHOLE_TOMATO(input);

	if (result.IsEmpty())
	{
		perror("Something failed");
		return;
	}

	// Convert the result to an UTF8 string and print it.
	String::Utf8Value utf8(result);

	memcpy_s(output, 2048, *utf8, utf8.length() + 1);
}

FH_API void Flathead::Execute(char *input, double &output)
{
	WHOLE_TOMATO(input);

	Local<Number> numResult = Handle<Number>::Cast(result);

	output = numResult->Value();
}

FH_API void Flathead::Execute(char *input, int &output)
{
	WHOLE_TOMATO(input);

	Local<Integer> numResult = Handle<Integer>::Cast(result);

	output = (int)numResult->Value();
}

FH_API void Flathead::Execute(char *input, int64_t &output)
{
	WHOLE_TOMATO(input);

	Local<Integer> numResult = Handle<Integer>::Cast(result);

	output = numResult->Value();
}

FH_API void Flathead::Execute(char *input, float &output)
{
	WHOLE_TOMATO(input);

	Local<Number> numResult = Handle<Number>::Cast(result);

	output = (float)numResult->Value();
}

FH_API void Flathead::Execute(char *input, bool &output)
{
	WHOLE_TOMATO(input);

	Local<Boolean> numResult = Handle<Boolean>::Cast(result);

	output = numResult->Value();
}

FH_API void Flathead::Tick(float delta)
{
	JSTick(delta);

	while (platform::PumpMessageLoop(g_Platform, g_CurrentVM))
	{
		continue;
	}
}

void Flathead::JSTick(float delta)
{
	INITIALIZE_SCOPE();
	Handle<Function> func = Handle<Function>::New(g_CurrentVM, g_Tick);

	Local<v8::Value> args[] = {
		Number::New(g_CurrentVM, delta),
	};

	func->Call(context->Global(), sizeof(args) / sizeof(args[0]), args);
}