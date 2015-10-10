
#include "stdafx.h"
#include "Types/Boolean.h"

using namespace Gneu::Types;

Boolean::Boolean(bool _value)
{
	value = _value;
}

bool Boolean::Value() const
{
	return value;
}

bool Boolean::IsBoolean() const
{
	return true;
}
