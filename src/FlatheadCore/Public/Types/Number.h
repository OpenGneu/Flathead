#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API Number : public Primitive
		{
		public:
			virtual operator double() const = 0;

			static Number *New(double);
			static Number *New(char *, double);
		};
	}
}