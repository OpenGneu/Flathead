#pragma once

#include "Types/Object.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class ObjectIMPL : public Object
		{
		public:
			ObjectIMPL(v8::Handle<v8::Value>);

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

		protected:
			v8::Persistent<v8::Object> persisted_value;
		};
	}
}