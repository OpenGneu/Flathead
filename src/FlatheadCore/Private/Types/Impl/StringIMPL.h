#pragma once

#include "Types/String.h"
#include "v8.h"

namespace Gneu
{
	namespace Types
	{
		class StringIMPL : public String
		{
		public:
			StringIMPL(v8::Handle<v8::Value>);

			void UTF8Value(char *) const;
			void Value(wchar_t *) const;

			int Length() const;

			bool Equals(char *) const;
			bool StrictEquals(char *) const;

			bool Equals(wchar_t *) const;
			bool StrictEquals(wchar_t *) const;

			bool IsString() const override;

		private:
			v8::Persistent<v8::String> persisted_value;
		};
	}
}
