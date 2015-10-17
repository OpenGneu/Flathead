#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(StringTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeStringTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupStringTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldBeAbleToRetrieveAString)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::Value *myStringValue = pFH->Get("myStringValue");

			Assert::IsNotNull(myStringValue);
			Assert::IsTrue(myStringValue->IsString());

			Types::String *myString = (Types::String *)myStringValue;

			Assert::IsNotNull(myString);
			Assert::IsTrue(myString->IsString());

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToRetrieveUTF8Value)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			myString->Value(buffer);

			Assert::AreEqual("testValue", buffer);

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToRetrieveLength)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			Assert::AreEqual(9, myString->Length());

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToEquateUTF8Strings)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->Equals("testValue"));
			Assert::IsFalse(myString->Equals("somethingElse"));

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToStrictlyEquateUTF16Strings)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->StrictEquals(L"testValue"));
			Assert::IsFalse(myString->StrictEquals(L"somethingElse"));

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToEquateUTF16Strings)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->Equals(L"testValue"));
			Assert::IsFalse(myString->Equals(L"somethingElse"));

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToStrictlyEquateUTF8Strings)
		{
			bool tmp;
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->StrictEquals("testValue"));
			Assert::IsFalse(myString->StrictEquals("somethingElse"));

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToRetrieveUTF16Value)
		{
			bool tmp;
			wchar_t buffer[128] = { 0 };
			pFH->Execute("myStringValue = 'testValue';", tmp);

			Types::String *myString = (Types::String *)pFH->Get("myStringValue");

			Assert::IsNotNull(myString);

			myString->Value(buffer);

			Assert::AreEqual(L"testValue", buffer);

			delete myString;
		}

		TEST_METHOD(ShouldBeAbleToSetAString)
		{
			char buffer[128] = { 0 };

			pFH->Set("myVar", "myStringValue");

			Types::String *myString = (Types::String *)pFH->Get("myVar");

			Assert::IsNotNull(myString);

			myString->Value(buffer);

			Assert::AreEqual("myStringValue", buffer);

			delete myString;
		}
	};
}