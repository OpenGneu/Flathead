#pragma once

#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		class FH_API String : public Primitive
		{
		public:
			virtual void Value(char *) const = 0;
			virtual void Value(wchar_t *) const = 0;

			virtual int Length() const = 0;

			virtual bool Equals(char *) const = 0;
			virtual bool StrictEquals(char *) const = 0;

			virtual bool Equals(wchar_t *) const = 0;
			virtual bool StrictEquals(wchar_t *) const = 0;

			static String *New(char *);
			static String *New(wchar_t *);
		};
	}
}