// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"
#include "ConsoleInterfaces.h"
#include "Flathead.h"
#include "Enumerations/LogLevels.h"

#include "v8.h"

using namespace Gneu;
using namespace Gneu::Interfaces;
using namespace v8;

void ConsoleInterfaces::Log(int type, const FunctionCallbackInfo<Value>& args)
{
	Handle<External> ext = Handle<External>::Cast(args.Data());
	Flathead *pFH = (Flathead *)ext->Value();
	int counter = 0;

	if (pFH->GetConfiguration()->LoggingFn() != NULL)
	{
		for (int i = 0; i < args.Length(); i++)
		{
			Local<Value> value = args[i];

			String::Utf8Value outputString(value);

			pFH->GetConfiguration()->LoggingFn()(type, *outputString);
			counter++;
		}
	}

	args.GetReturnValue().Set(counter);
}

void ConsoleInterfaces::Log(const FunctionCallbackInfo<Value>& args)
{
	Log(LogLevels::Log, args);
}

void ConsoleInterfaces::Info(const FunctionCallbackInfo<Value>& args)
{
	Log(LogLevels::Info, args);
}

void ConsoleInterfaces::Warn(const FunctionCallbackInfo<Value>& args)
{
	Log(LogLevels::Warn, args);
}

void ConsoleInterfaces::Error(const FunctionCallbackInfo<Value>& args)
{
	Log(LogLevels::Error, args);
}

void ConsoleInterfaces::Assert(const FunctionCallbackInfo<Value>& args)
{
	Handle<External> ext = Handle<External>::Cast(args.Data());
	Flathead *pFH = (Flathead *)ext->Value();
	int counter = 0;

	if (args.Length() == 0)
	{
		pFH->GetConfiguration()->LoggingFn()(LogLevels::Assert, "");
		return;
	}

	Local<Value> value = args[0];

	if (value->IsTrue())
	{
		args.GetReturnValue().Set(counter);
		return;
	}

	if (pFH->GetConfiguration()->LoggingFn() != NULL)
	{
		for (int i = 1; i < args.Length(); i++)
		{
			Local<Value> value = args[i];

			String::Utf8Value outputString(value);

			pFH->GetConfiguration()->LoggingFn()(LogLevels::Assert, *outputString);
			counter++;
		}
	}

	args.GetReturnValue().Set(counter);
}