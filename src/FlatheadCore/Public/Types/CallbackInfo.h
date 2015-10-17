#pragma once

#include "Value.h"

namespace Gneu
{
	namespace Types
	{
		class CallbackInfo 
		{
		public:
			virtual Gneu::Types::Value *operator[](int ndx) const = 0;
		};
	}
}