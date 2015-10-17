#pragma once

#include "Types/Object.h"
#include "Types/CallbackInfo.h"

namespace Gneu
{
	namespace Types
	{
		typedef void(*VoidFunction)(CallbackInfo &args);
		typedef bool(*BoolFunction)(CallbackInfo &args);
		typedef double(*DoubleFunction)(CallbackInfo &args);
		typedef float(*FloatFunction)(CallbackInfo &args);
		typedef int(*IntFunction)(CallbackInfo &args);
		typedef void *(*VoidPFunction)(CallbackInfo &args);

		class Function : public Object
		{
		public:
		};
	}
}