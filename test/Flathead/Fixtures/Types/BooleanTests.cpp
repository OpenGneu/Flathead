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
			pFH->Execute("myBool = true;", myBool);

			Types::Value *myBoolValue = pFH->Get("myBool");

			Assert::IsNotNull(myBoolValue);
			Assert::IsTrue(myBoolValue->IsBoolean());

			Types::Boolean *myBoolean = (Types::Boolean *)myBoolValue;

			Assert::IsNotNull(myBoolValue);
			Assert::IsTrue(myBoolValue->IsBoolean());
			// Assert::IsTrue(*myBoolValue);
		}
	};
}