#pragma once

#include "Types/Number.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class NumberIMPL : public Number
		{
		public:
			NumberIMPL(v8::Handle<v8::Value>);

			bool IsNumber() const override;

			operator double() const;

			bool IsInt32() const;
			bool IsUint32() const;

		protected:
			v8::Persistent<v8::Number> persisted_value;
		};
	}
}
