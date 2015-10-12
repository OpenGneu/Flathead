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
		};
	}
}