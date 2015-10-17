#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Number.h"

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
	};
}
