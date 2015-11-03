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

			static Function *New(char *, VoidFunction);
			static Function *New(char *, IntFunction);
			static Function *New(char *, DoubleFunction);
			static Function *New(char *, FloatFunction);
			static Function *New(char *, VoidPFunction);
			static Function *New(char *, BoolFunction);
			static Function *New(char *, StringFunction);
			static Function *New(char *, WideStringFunction);
		};
	}
}