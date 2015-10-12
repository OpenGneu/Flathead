#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class String : public Primitive
		{
		public:
			virtual void UTF8Value(char *) const = 0;
			virtual void Value(wchar_t *) const = 0;
		};
	}
}