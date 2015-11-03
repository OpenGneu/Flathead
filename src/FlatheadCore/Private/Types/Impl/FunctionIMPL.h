#pragma once

#include "Types/Function.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class FunctionIMPL : public Function
		{
		public:
			FunctionIMPL(v8::Handle<v8::Value>);
			FunctionIMPL(VoidFunction);
			FunctionIMPL(IntFunction);
			FunctionIMPL(BoolFunction);
			FunctionIMPL(VoidPFunction);
			FunctionIMPL(DoubleFunction);
			FunctionIMPL(FloatFunction);
			FunctionIMPL(StringFunction);
			FunctionIMPL(WideStringFunction);

			FunctionIMPL(char *, VoidFunction);
			FunctionIMPL(char *, IntFunction);
			FunctionIMPL(char *, BoolFunction);
			FunctionIMPL(char *, VoidPFunction);
			FunctionIMPL(char *, DoubleFunction);
			FunctionIMPL(char *, FloatFunction);
			FunctionIMPL(char *, StringFunction);
			FunctionIMPL(char *, WideStringFunction);

			bool IsObject() const override;
			bool IsFunction() const override;
			bool IsArray() const override;
			bool IsBooleanObject() const override;
			bool IsDate() const override;
			bool IsPromise() const override;
			bool IsRegExp() const override;
			bool IsNumberObject() const override;
			bool IsStringObject() const override;
			bool IsSymbol() const override;

			Value *Get(char *) const;
			bool Set(char *, char *) const;
			bool Set(char *, double) const;
			bool Set(char *, int) const;
			bool Set(char *, bool) const;
			bool Set(char *, VoidFunction) const;
			bool Set(char *, IntFunction) const;
			bool Set(char *, BoolFunction) const;
			bool Set(char *, DoubleFunction) const;
			bool Set(char *, FloatFunction) const;
			bool Set(char *, VoidPFunction) const;
			bool Set(char *, StringFunction) const;
			bool Set(char *, WideStringFunction) const;

			void *GetReference() const;

			v8::Persistent<v8::Function> persisted_value;
		};
	}
}
