#include "stdafx.h"

#include "v8.h"

#include "Types/Value.h"
#include "Types/Translate.h"
#include "Types/Boolean.h"

using namespace v8;
using namespace Gneu::Types;

Gneu::Types::Value *Translate::ToFlathead(v8::Handle<v8::Value>)
{
	return new Gneu::Types::Boolean();
}