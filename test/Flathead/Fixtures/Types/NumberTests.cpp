#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Number.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(NumberTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeNumberTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupNumberTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldBeAbleToRetrieveANumber)
		{
			bool tmp;
			pFH->Execute("myNumberValue = 42.0;", tmp);

			Types::Value *myNumberValue = pFH->Get("myNumberValue");

			Assert::IsNotNull(myNumberValue);
			Assert::IsTrue(myNumberValue->IsNumber());

			Types::Number *myNumber = (Types::Number *)myNumberValue;

			Assert::IsNotNull(myNumber);
			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myNumber;
		}

		TEST_METHOD(ShouldBeAbleToSetANumberWithAnInt)
		{
			pFH->Set("myVar", 42);

			Types::Value *myNumberValue = pFH->Get("myVar");

			Assert::IsNotNull(myNumberValue);
			Assert::IsTrue(myNumberValue->IsNumber());

			Types::Number *myNumber = (Types::Number *)myNumberValue;

			Assert::IsNotNull(myNumber);
			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myNumber;
		}

		TEST_METHOD(ShouldBeAbleToSetANumberWithADouble)
		{
			pFH->Set("myVar", 42.0);

			Types::Value *myNumberValue = pFH->Get("myVar");

			Assert::IsNotNull(myNumberValue);
			Assert::IsTrue(myNumberValue->IsNumber());

			Types::Number *myNumber = (Types::Number *)myNumberValue;

			Assert::IsNotNull(myNumber);
			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myNumber;
		}

		TEST_METHOD(ShouldBeAbleToSetANumberWithAfloat)
		{
			pFH->Set("myVar", 42.0f);

			Types::Value *myNumberValue = pFH->Get("myVar");

			Assert::IsNotNull(myNumberValue);
			Assert::IsTrue(myNumberValue->IsNumber());

			Types::Number *myNumber = (Types::Number *)myNumberValue;

			Assert::IsNotNull(myNumber);
			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myNumber;
		}

		TEST_METHOD(ShouldBeAbleToSetANumberWithNumberType)
		{
			Types::Number *b = Types::Number::New(42);
			Types::Number *b2 = Types::Number::New(52);

			pFH->Set("myVar", b);
			pFH->Set("myVar2", b2);

			Types::Value *myNumberValue = pFH->Get("myVar");
			Types::Value *myNumberValue2 = pFH->Get("myVar2");

			Assert::IsNotNull(myNumberValue);
			Assert::IsTrue(myNumberValue->IsNumber());

			Assert::IsNotNull(myNumberValue2);
			Assert::IsTrue(myNumberValue2->IsNumber());

			Types::Number *myNumber = (Types::Number *)myNumberValue;
			Types::Number *myNumber2 = (Types::Number *)myNumberValue2;

			Assert::IsNotNull(myNumber);
			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			Assert::IsNotNull(myNumber2);
			Assert::IsTrue(myNumber2->IsNumber());
			Assert::AreEqual(52.0, (double)*myNumber2);

			delete myNumber;
			delete myNumber2;

			delete b;
			delete b2;
		}
	};
}
