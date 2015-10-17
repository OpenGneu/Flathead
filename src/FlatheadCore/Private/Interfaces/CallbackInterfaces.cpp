// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"
#include "CallbackInterfaces.h"

#include "Private/Types/Impl/CallbackInfoImpl.h"
#include "Types/Function.h"

#include "v8.h"

using namespace Gneu::Interfaces;

void CallbackInterfaces::VoidCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
}

void CallbackInterfaces::BoolCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{

}

void CallbackInterfaces::IntCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{

}

void CallbackInterfaces::DoubleCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{

}

void CallbackInterfaces::FloatCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{

}

void CallbackInterfaces::VoidPointerCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	Types::CallbackInfoIMPL cb(args);

	v8::Handle<v8::External> ext = v8::Handle<v8::External>::Cast(args.Data());
	Types::VoidPFunction icb = (Types::VoidPFunction)ext->Value();

	args.GetReturnValue().Set((int)icb(cb));
}