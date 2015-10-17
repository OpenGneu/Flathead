#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class Object : public Value
		{
		public:
			virtual Types::Value *Get(char *) const = 0;

			virtual bool Set(char *, char *) const = 0;
			virtual bool Set(char *, double) const = 0;
			virtual bool Set(char *, int) const = 0;
			virtual bool Set(char *, bool) const = 0;
		};
	}
}