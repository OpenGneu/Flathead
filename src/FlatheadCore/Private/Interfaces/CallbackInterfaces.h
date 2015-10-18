// Copyright 2015 Gneu LLC. All Rights Reserved.

#pragma once

#include "v8.h"

namespace Gneu
{
	namespace Interfaces
	{
		class CallbackInterfaces
		{
		public:
			static void VoidCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void BoolCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void IntCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void DoubleCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void FloatCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void VoidPointerCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void StringCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void WideStringCallback(const v8::FunctionCallbackInfo<v8::Value>& args);
		};
	}
}
