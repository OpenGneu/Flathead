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

		TEST_METHOD(ShouldBeAbleToRetrieveABoolean)
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

		TEST_METHOD(ShouldBeAbleToSetABoolWithBooleanType)
		{
			Types::Boolean *b = Types::Boolean::New(true);
			Types::Boolean *b2 = Types::Boolean::New(false);
			pFH->Set("myVar", b);
			pFH->Set("myVar2", b2);

			Types::Value *myReturnValue = pFH->Get("myVar");
			Types::Value *myReturnValue2 = pFH->Get("myVar2");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsBoolean());
			Assert::IsNotNull(myReturnValue2);
			Assert::IsTrue(myReturnValue2->IsBoolean());

			Types::Boolean *myBoolean = (Types::Boolean *)myReturnValue;
			Types::Boolean *myBoolean2 = (Types::Boolean *)myReturnValue2;

			Assert::IsNotNull(myBoolean);
			Assert::IsTrue(myBoolean->IsBoolean());
			Assert::IsTrue(*myBoolean);

			Assert::IsNotNull(myBoolean2);
			Assert::IsTrue(myBoolean2->IsBoolean());
			Assert::IsFalse(*myBoolean2);

			delete myBoolean; 
			delete myBoolean2;
			delete b;
			delete b2;
		}

		TEST_METHOD(ShouldBeAbleToExposeANamedBoolean)
		{
			Types::Boolean *b = Types::Boolean::New("myBool", true);
		
			Types::Value *myReturnValue = pFH->Get("myBool");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsBoolean());

			Types::Boolean *myBoolean = (Types::Boolean *)myReturnValue;

			Assert::IsNotNull(myBoolean);
			Assert::IsTrue(myBoolean->IsBoolean());
			Assert::IsTrue(*myBoolean);

			delete myBoolean;
			delete b;
		}
	};
}