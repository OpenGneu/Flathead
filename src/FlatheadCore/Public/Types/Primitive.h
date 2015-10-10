// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#include "Value.h"

#pragma once



namespace Gneu
{
	namespace Types
	{
		class FH_API Primitive : public Value
		{
		public:
			Primitive(int flag);
			Primitive();

			bool IsUndefined() const override;
			bool IsNull() const override;

		protected:
			int type;
		};
	}
}