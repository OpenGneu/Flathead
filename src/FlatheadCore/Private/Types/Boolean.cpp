#include "stdafx.h"
#include "Types/Boolean.h"
#include "Private/Types/impl/BooleanIMPL.h"

using namespace Gneu::Types;

Gneu::Types::Boolean *Gneu::Types::Boolean::New(bool value)
{
	return new Gneu::Types::BooleanIMPL(value);
}
