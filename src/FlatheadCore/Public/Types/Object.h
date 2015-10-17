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
		};
	}
}