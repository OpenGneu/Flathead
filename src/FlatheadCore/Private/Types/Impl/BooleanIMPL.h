#pragma once

#include "Types/Boolean.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class BooleanIMPL : public Boolean
		{
		public:
			BooleanIMPL(v8::Handle<v8::Value>);
			BooleanIMPL(char *, bool);
			BooleanIMPL(bool);

			operator bool() const override;

			bool IsBoolean() const override;

			v8::Persistent<v8::Boolean> persisted_value;
		};
	}
}
