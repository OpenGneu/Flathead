// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"
#include "ModuleInterfaces.h"
#include "Flathead.h"
#include <sys/stat.h>

#include "v8.h"

using namespace Gneu;
using namespace Gneu::Interfaces;
using namespace v8;

void ModuleInterfaces::Exists(const FunctionCallbackInfo<Value>& args)
{
	struct stat buf;

	// Filename
	if (args.Length() != 1)
	{
		args.GetReturnValue().SetUndefined();
		return; // invalid arguments
	}

	v8::String::Utf8Value Filename(args[0]);

	args.GetReturnValue().Set(0 == stat(*Filename, &buf));
}

void ModuleInterfaces::LoadModule(const v8::FunctionCallbackInfo<v8::Value>& args)
{	// Filename
	if (args.Length() != 1)
	{
		args.GetReturnValue().SetUndefined();
		return; // invalid arguments
	}

	// Find Library in lib paths
	v8::String::Utf8Value Filename(args[0]);

	FILE* file;

	if (fopen_s(&file, *Filename, "rb"))
	{
		args.GetReturnValue().SetUndefined();
		return; // Couldnt find/open the file
	}

	fseek(file, 0, SEEK_END);

	int size = ftell(file);
	rewind(file);

	char* result = new char[size + 1];
	result[size] = '\0';
	int read = static_cast<int>(fread_s(result, size, 1, size, file));
	fclose(file);

	args.GetReturnValue().Set(v8::String::NewFromUtf8(args.GetIsolate(), result));
}

void ModuleInterfaces::Execute(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Isolate::Scope isoScope(args.GetIsolate());
	HandleScope handScope(args.GetIsolate());
	TryCatch try_catch;

	try_catch.SetVerbose(true);

	// Filename, FileContents
	if (args.Length() != 2)
	{
		args.GetReturnValue().SetUndefined();
		return;
	}

	Handle<v8::String> source = Handle<v8::String>::Cast(args[1]);
	Handle<v8::String> name = Handle<v8::String>::Cast(args[0]);

	ScriptOrigin origin(name);

	Handle<Script> script = Script::Compile(source, &origin);
	if (script.IsEmpty()) {

		v8::String::Utf8Value error(try_catch.Exception());
		// use v8 to throw an exception here.
		// The script failed to compile; bail out.
		args.GetReturnValue().SetUndefined();
		return; // Bad compile
	}

	Local<v8::Value> result = script->Run();

	if (result.IsEmpty()) {

		v8::String::Utf8Value error(try_catch.Exception());
		// use v8 to throw an exception here.
		// The script failed to run; bail out.
		args.GetReturnValue().SetUndefined();
		return; // Bad run
	}

	args.GetReturnValue().Set(result);
}