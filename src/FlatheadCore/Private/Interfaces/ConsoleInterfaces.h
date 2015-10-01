// Copyright 2015 Gneu LLC. All Rights Reserved.

#pragma once

#include "v8.h"

namespace Gneu
{
	namespace Interfaces
	{
		class ConsoleInterfaces
		{
		public:
			static void Log(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void Info(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void Warn(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void Error(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void Assert(const v8::FunctionCallbackInfo<v8::Value>& args);

		private:
			static void Log(int type, const v8::FunctionCallbackInfo<v8::Value>& args);
		};
	}
}