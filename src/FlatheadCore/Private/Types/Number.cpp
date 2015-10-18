#include "stdafx.h"
#include "Types/Number.h"
#include "Private/Types/impl/NumberIMPL.h"

using namespace Gneu::Types;

Gneu::Types::Number *Gneu::Types::Number::New(double value)
{
	return new Gneu::Types::NumberIMPL(value);
}
