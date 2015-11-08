#pragma once

#include "Value.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API CallbackInfo
		{
		public:
			virtual Gneu::Types::Value *operator[](int ndx) const = 0;
			virtual void *Data() const = 0;
		};
	}
}