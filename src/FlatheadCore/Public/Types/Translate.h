#pragma once

#include "v8.h"
#include "Value.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API Translate
		{
		public:
			static Types::Value *ToFlathead(v8::Handle<v8::Value>);
		};
	}
}