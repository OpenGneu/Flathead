// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#include "Primitive.h"

#pragma once

namespace Gneu
{
	namespace Types
	{
		class FH_API Boolean : public Primitive
		{
		public:

			Boolean(bool value);

			// Explicit Getter
			bool Value() const;

			// Implicit Cast to bool
			operator bool() const { return Value(); }

			bool IsBoolean() const override;
		private: 
			bool value;
		};
	}
}