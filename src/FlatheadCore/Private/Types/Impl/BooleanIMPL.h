#pragma once

#include "Types/Boolean.h"

namespace Gneu
{
	namespace Types
	{
		class BooleanIMPL : public Boolean
		{
		public:
			BooleanIMPL(v8::Handle<v8::Value>);

			operator bool() const override;

			bool IsBoolean() const override;

		private:
			v8::Persistent<v8::Boolean> persisted_value;
		};
	}
}
