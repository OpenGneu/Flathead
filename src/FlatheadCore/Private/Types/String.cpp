#include "stdafx.h"
#include "Types/String.h"
#include "Private/Types/impl/StringIMPL.h"

using namespace Gneu::Types;

Gneu::Types::String *Gneu::Types::String::New(char *value)
{
	return new Gneu::Types::StringIMPL(value);
}

Gneu::Types::String *Gneu::Types::String::New(wchar_t *value)
{
	return new Gneu::Types::StringIMPL(value);
}
