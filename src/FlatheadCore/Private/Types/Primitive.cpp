
#include "stdafx.h"
#include "Types/Primitive.h"
#include "Enumerations/PrimitiveTypeFlags.h"

using namespace Gneu::Types;

Primitive::Primitive(int flag)
{
	if (flag < PrimitiveType::Count)
	{
		type = (PrimitiveType)flag;
	}
	else
	{
		type = PrimitiveType::Undefined;
	}
}

Primitive::Primitive()
{
	type = PrimitiveType::Defined;
}

bool Primitive::IsUndefined() const
{
	return type == PrimitiveType::Undefined;
}

bool Primitive::IsNull() const
{
	return type == PrimitiveType::Null;
}