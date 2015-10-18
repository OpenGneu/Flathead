#include "stdafx.h"
#include "Types/Object.h"
#include "Private/Types/impl/ObjectIMPL.h"

using namespace Gneu::Types;

Gneu::Types::Object *Gneu::Types::Object::New()
{
	return new Gneu::Types::ObjectIMPL();
}
