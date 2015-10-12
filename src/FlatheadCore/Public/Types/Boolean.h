#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class Boolean : public Primitive
		{
		public:
			virtual operator bool() const = 0;
		};
	}
}