// Copyright 2015 Gneu LLC. All Rights Reserved.

#pragma once

#include "v8.h"

namespace Gneu
{
	namespace Interfaces
	{
		class ModuleInterfaces
		{
		public:
			static void Exists(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void LoadModule(const v8::FunctionCallbackInfo<v8::Value>& args);
			static void Execute(const v8::FunctionCallbackInfo<v8::Value>& args);
			
		private:
		};
	}
}