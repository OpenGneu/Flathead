#pragma once

#include "v8.h"
#include "Value.h"

namespace Gneu
{
	namespace Types
	{
		class Translate
		{
		public:
			static Types::Value *ToFlathead(v8::Handle<v8::Value>);
		};
	}
}