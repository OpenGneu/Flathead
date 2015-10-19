#pragma once

#include "Types/CallbackInfo.h"
#include "Types/Primitive.h"

namespace Gneu
{
	namespace Types
	{
		typedef void(*VoidFunction)(CallbackInfo &args);
		typedef bool(*BoolFunction)(CallbackInfo &args);
		typedef double(*DoubleFunction)(CallbackInfo &args);
		typedef float(*FloatFunction)(CallbackInfo &args);
		typedef int(*IntFunction)(CallbackInfo &args);
		typedef char *(*StringFunction)(CallbackInfo &args);
		typedef wchar_t *(*WideStringFunction)(CallbackInfo &args);
		typedef void *(*VoidPFunction)(CallbackInfo &args);

		class FH_API Object : public Value
		{
		public:
			virtual Types::Value *Get(char *) const = 0;

			virtual bool Set(char *, char *) const = 0;
			virtual bool Set(char *, double) const = 0;
			virtual bool Set(char *, int) const = 0;
			virtual bool Set(char *, bool) const = 0;
			virtual bool Set(char *, VoidFunction) const = 0;
			virtual bool Set(char *, IntFunction) const = 0;
			virtual bool Set(char *, BoolFunction) const = 0;
			virtual bool Set(char *, DoubleFunction) const = 0;
			virtual bool Set(char *, FloatFunction) const = 0;
			virtual bool Set(char *, VoidPFunction) const = 0;
			virtual bool Set(char *, StringFunction) const = 0;
			virtual bool Set(char *, WideStringFunction) const = 0;

			virtual void *GetReference() const = 0;

			static Object *New();
			static Object *New(char *, void *);
		};
	}
}