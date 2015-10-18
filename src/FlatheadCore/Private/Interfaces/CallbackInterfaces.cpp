// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"
#include "CallbackInterfaces.h"

#include "Private/Types/Impl/CallbackInfoImpl.h"
#include "Types/Function.h"

#include "v8.h"

using namespace Gneu::Interfaces;

void CallbackInterfaces::VoidCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::VoidFunction icb = (Types::VoidFunction)ext->Value();
	
	icb(cb);
	
	args.GetReturnValue().SetUndefined();
}

void CallbackInterfaces::BoolCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::BoolFunction icb = (Types::BoolFunction)ext->Value();

	args.GetReturnValue().Set((bool)icb(cb));
}

void CallbackInterfaces::IntCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::IntFunction icb = (Types::IntFunction)ext->Value();

	args.GetReturnValue().Set((int)icb(cb));
}

void CallbackInterfaces::DoubleCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::DoubleFunction icb = (Types::DoubleFunction)ext->Value();

	args.GetReturnValue().Set((double)icb(cb));
}

void CallbackInterfaces::FloatCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::FloatFunction icb = (Types::FloatFunction)ext->Value();

	args.GetReturnValue().Set((float)icb(cb));
}

void CallbackInterfaces::VoidPointerCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::VoidPFunction icb = (Types::VoidPFunction)ext->Value();

	args.GetReturnValue().Set((int)icb(cb));
}

void CallbackInterfaces::StringCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::StringFunction icb = (Types::StringFunction)ext->Value();

	char *result = icb(cb);
	v8::Local<v8::String> v8Result = v8::String::NewFromUtf8(args.GetIsolate(), result);

	args.GetReturnValue().Set(v8Result);
}

void CallbackInterfaces::WideStringCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::WideStringFunction icb = (Types::WideStringFunction)ext->Value();

	wchar_t *result = icb(cb);
	v8::Local<v8::String> v8Result = v8::String::NewFromTwoByte(args.GetIsolate(), (uint16_t *)result);

	args.GetReturnValue().Set(v8Result);
}