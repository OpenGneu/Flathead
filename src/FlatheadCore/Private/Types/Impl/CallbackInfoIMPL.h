#pragma once

#include "Types/CallbackInfo.h"
#include "Types/Value.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class CallbackInfoIMPL : public CallbackInfo
		{
		public:
			CallbackInfoIMPL(const v8::FunctionCallbackInfo<v8::Value>& args);
			Types::Value *operator[](int ndx) const;
			void *Data() const;

		private:
			const v8::FunctionCallbackInfo<v8::Value> *arguments;
		};
	}
}
