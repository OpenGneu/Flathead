#include "stdafx.h"

#include "v8.h"

#include "Types/Value.h"
#include "Types/Translate.h"
#include "Impl/BooleanIMPL.h"
#include "Impl/PrimitiveIMPL.h"
#include "Impl/StringIMPL.h"
#include "Impl/NumberIMPL.h"

using namespace v8;
using namespace Gneu::Types;

Gneu::Types::Value *Translate::ToFlathead(v8::Handle<v8::Value> v8Value)
{
	if (v8Value->IsBoolean())
	{
		return new Gneu::Types::BooleanIMPL(v8Value);
	}

	if (v8Value->IsString())
	{
		return new Gneu::Types::StringIMPL(v8Value);
	}

	if (v8Value->IsNumber())
	{
		return new Gneu::Types::NumberIMPL(v8Value);
	}

	return new Gneu::Types::PrimitiveIMPL(v8Value);
}