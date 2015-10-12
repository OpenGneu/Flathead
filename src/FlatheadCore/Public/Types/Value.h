#pragma once

namespace Gneu
{
	namespace Types
	{
		class Value
		{
		public:
			virtual bool IsBoolean() const; 
			virtual bool IsUndefined() const;
			virtual bool IsNull() const; 
			virtual bool IsString() const;
			virtual bool IsNumber() const;
			virtual bool IsObject() const;
			virtual bool IsArray() const;
			virtual bool IsFunction() const;
			virtual bool IsBooleanObject() const;
			virtual bool IsDate() const;
			virtual bool IsPromise() const; 
			virtual bool IsNumberObject() const;
			virtual bool IsRegExp() const;
			virtual bool IsStringObject() const;
			virtual bool IsSymbol() const;
			virtual bool IsInt32() const;
			virtual bool IsUint32() const;
		};
	}
}