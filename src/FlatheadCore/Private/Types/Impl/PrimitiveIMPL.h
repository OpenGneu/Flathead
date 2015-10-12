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

		private:
			v8::Persistent<v8::Value> persisted_value;
		};
	}
}