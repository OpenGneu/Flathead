#pragma once

#include "Types/Value.h"

namespace Gneu
{
	namespace Types
	{
		class Boolean : public Value
		{
			bool IsBoolean() const override;
		};
	}
}