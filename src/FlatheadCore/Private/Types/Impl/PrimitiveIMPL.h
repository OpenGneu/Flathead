#pragma once

#include "Types/Primitive.h"
#include "Enumerations/PrimitiveTypeFlags.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class PrimitiveIMPL : public Primitive
		{
		public: 
			PrimitiveIMPL(v8::Handle<v8::Value>);

			bool IsUndefined() const override;
			bool IsNull() const override;
			bool IsBoolean() const override;
			bool IsString() const override;
			bool IsNumber() const override;
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
			bool IsInt32() const override; 
			bool IsUint32() const override;

		protected:
			v8::Persistent<v8::Value> persisted_value;
		};
	}
}