#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Boolean.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(BooleanTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeModuleTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupModuleTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldBeAbleToCreateABoolean)
		{
			bool myBool;
			pFH->Execute("myTrueBool = true; myFalseBool = false;", myBool);

			Types::Value *myTrueBoolValue = pFH->Get("myTrueBool");
			Types::Value *myFalseBoolValue = pFH->Get("myFalseBool");

			Assert::IsNotNull(myTrueBoolValue);
			Assert::IsTrue(myTrueBoolValue->IsBoolean());

			Types::Boolean *myBoolean = (Types::Boolean *)myTrueBoolValue;

			Assert::IsNotNull(myBoolean);
			Assert::IsTrue(myBoolean->IsBoolean());
			Assert::IsTrue(*myBoolean);

			Assert::IsNotNull(myFalseBoolValue);
			Assert::IsTrue(myFalseBoolValue->IsBoolean());

			myBoolean = (Types::Boolean *)myFalseBoolValue;

			Assert::IsNotNull(myBoolean);
			Assert::IsTrue(myBoolean->IsBoolean());
			Assert::IsFalse(*myBoolean);
		}
	};
}