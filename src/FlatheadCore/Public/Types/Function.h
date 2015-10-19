#pragma once

#include "Types/Object.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API Function : public Object
		{
		public:

			static Function *New(VoidFunction);
			static Function *New(IntFunction);
			static Function *New(DoubleFunction);
			static Function *New(FloatFunction);
			static Function *New(VoidPFunction);
			static Function *New(BoolFunction);
			static Function *New(StringFunction);
			static Function *New(WideStringFunction);
		};
	}
}