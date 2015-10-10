// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#include "Primitive.h"
#include "Boolean.h"

#pragma once

namespace Gneu
{
	namespace Types
	{
		class FH_API Constants 
		{
		public:

			static const Primitive Null;
			static const Primitive Undefined;

			static const Boolean True;
			static const Boolean False;
		};
	}
}