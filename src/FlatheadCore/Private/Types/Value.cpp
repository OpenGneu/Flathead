
#include "stdafx.h"
#include "Types/Value.h"

using namespace Gneu::Types;

bool Value::IsBoolean() const
{
	return false;
}

bool Value::IsArray() const
{
	return false;
}

bool Value::IsBooleanObject() const
{
	return false;
}

bool Value::IsDate() const
{
	return false;
}

bool Value::IsExternal() const
{
	return false;
}

bool Value::IsFalse() const
{
	return true;
}

bool Value::IsFunction() const
{
	return false;
}

bool Value::IsInt32() const
{
	return false;
}

bool Value::IsNativeError() const
{
	return false;
}

bool Value::IsNull() const
{
	return false;
}

bool Value::IsNumber() const
{
	return false;
}

bool Value::IsNumberObject() const
{
	return false;
}

bool Value::IsObject() const
{
	return false;
}

bool Value::IsRegExp() const
{
	return false;
}

bool Value::IsString() const
{
	return false;
}

bool Value::IsStringObject() const
{
	return false;
}

bool Value::IsTrue() const
{
	return false;
}

bool Value::IsUint32() const
{
	return false;
}

bool Value::IsUndefined() const
{
	return true;
}