#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(FlatheadExecuteTests), RequiresFlathead
	{

	public:
		TEST_CLASS_INITIALIZE(InitializeFlatheadExecutionTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupFlatheadExecutionTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldSupportStrings)
		{
			char buffer[2048];

			pFH->Execute("1+1;", (char *)buffer);

			Assert::AreEqual("2", buffer);
		}

		TEST_METHOD(ShouldSupportNumbers)
		{
			double result;

			pFH->Execute("1+1;", result);

			Assert::AreEqual(2.0, result);
		}

		TEST_METHOD(ShouldSupportIntegers)
		{
			int result;

			pFH->Execute("1+1;", result);

			Assert::AreEqual(2, result);
		}

		TEST_METHOD(ShouldSupportLongIntegers)
		{
			int64_t result;

			pFH->Execute("1+1;", result);

			Assert::IsTrue((int64_t)2 == result);
		}

		TEST_METHOD(ShouldSupportFloats)
		{
			float result;

			pFH->Execute("1+1;", result);

			Assert::AreEqual(2.0f, result);
		}

		TEST_METHOD(ShouldSupportBooleans)
		{
			bool result;

			pFH->Execute("1 == 1;", result);

			Assert::IsTrue(result);
		}
	};
}