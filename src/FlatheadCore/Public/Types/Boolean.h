#pragma once

#include "Types/Primitive.h"
#include "API.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API Boolean : public Primitive
		{
		public:
			virtual operator bool() const = 0;
			static Boolean *New(bool);
		};
	}
}