#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class Number : public Primitive
		{
		public:
			virtual operator double() const = 0;
		};
	}
}