#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"
#include "Types/Value.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(GettingFromJSTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeConsoleTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupConsoleTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldHaveGetMethod)
		{
			pFH->Get("MyVar");
		}

		TEST_METHOD(GetMethodShouldReturnPointer)
		{
			Assert::IsNotNull(pFH->Get("v8"));
		}

		TEST_METHOD(Undefined)
		{
			const Types::Value *pValue = pFH->Get("MyUndefinedVar");

			Assert::IsNotNull(pValue);
			Assert::IsTrue(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Bools)
		{
			bool tmp;

			pFH->Execute("myVar = true;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsTrue(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Strings)
		{
			bool tmp;

			pFH->Execute("myVar = 'string';", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsTrue(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Null)
		{
			bool tmp;

			pFH->Execute("myVar = null;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsTrue(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Numbers)
		{
			bool tmp;

			pFH->Execute("myVar = 42.125;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsTrue(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Objects)
		{
			bool tmp;

			pFH->Execute("myVar = {};", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Functions)
		{
			bool tmp;

			pFH->Execute("myVar = function () {};", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsTrue(pValue->IsFunction());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Arrays)
		{
			bool tmp;

			pFH->Execute("myVar = [];", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsTrue(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(BooleanObjects)
		{
			bool tmp;

			pFH->Execute("myVar = new Boolean();", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsTrue(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(DateObjects)
		{
			bool tmp;

			pFH->Execute("myVar = new Date();", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsTrue(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}
		/*
		TEST_METHOD(PromiseObject)
		{
			bool tmp;

			pFH->Execute("myVar = new Promise();", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsTrue(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}*/

		TEST_METHOD(RegExpObject)
		{
			bool tmp;

			pFH->Execute("myVar = /^a/;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsTrue(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(NumberObject)
		{
			bool tmp;

			pFH->Execute("myVar = new Number(42);", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsTrue(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(StringObject)
		{
			bool tmp;

			pFH->Execute("myVar = new String('');", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsTrue(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(Int32)
		{
			bool tmp;

			pFH->Execute("myVar = -42;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsTrue(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsTrue(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}

		TEST_METHOD(UInt32)
		{
			bool tmp;

			pFH->Execute("myVar = 42;", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsTrue(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsFalse(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsFalse(pValue->IsSymbol());
			Assert::IsTrue(pValue->IsInt32());
			Assert::IsTrue(pValue->IsUint32());
		}

		/*
		TEST_METHOD(SymbolObject)
		{
			bool tmp;

			pFH->Execute("myVar = new Symbol();", tmp);

			const Types::Value *pValue = pFH->Get("myVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsFalse(pValue->IsBoolean());
			Assert::IsFalse(pValue->IsNull());
			Assert::IsFalse(pValue->IsString());
			Assert::IsFalse(pValue->IsNumber());
			Assert::IsFalse(pValue->IsFunction());
			Assert::IsTrue(pValue->IsObject());
			Assert::IsFalse(pValue->IsArray());
			Assert::IsFalse(pValue->IsBooleanObject());
			Assert::IsFalse(pValue->IsDate());
			Assert::IsFalse(pValue->IsPromise());
			Assert::IsFalse(pValue->IsRegExp());
			Assert::IsFalse(pValue->IsNumberObject());
			Assert::IsFalse(pValue->IsStringObject());
			Assert::IsTrue(pValue->IsSymbol());
			Assert::IsFalse(pValue->IsInt32());
			Assert::IsFalse(pValue->IsUint32());
		}*/
	};
}