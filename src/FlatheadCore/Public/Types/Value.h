// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#pragma once

namespace Gneu
{
	namespace Types
	{
		class FH_API Value
		{
		public:
			virtual bool IsArray() const;
			virtual bool IsBoolean() const;
			virtual bool IsBooleanObject() const;
			virtual bool IsDate() const;
			virtual bool IsExternal() const;
			virtual bool IsFalse() const;
			virtual bool IsFunction() const;
			virtual bool IsInt32() const;
			virtual bool IsNativeError() const;
			virtual bool IsNull() const;
			virtual bool IsNumber() const;
			virtual bool IsNumberObject() const;
			virtual bool IsObject() const;
			virtual bool IsRegExp() const;
			virtual bool IsString() const;
			virtual bool IsStringObject() const;
			virtual bool IsTrue() const;
			virtual bool IsUint32() const;
			virtual bool IsUndefined() const;
		}; 
	}
}