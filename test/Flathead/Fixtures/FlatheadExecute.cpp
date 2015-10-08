#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(FlatheadExecuteTests)
	{
		static Flathead *pFH;

	public:
		TEST_CLASS_INITIALIZE(InitializeFlatheadExecutionTests)
		{
			pFH = new Flathead();
		}

		TEST_CLASS_CLEANUP(CleanupFlatheadExecuteTests)
		{
			delete pFH;
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

	Flathead *FlatheadExecuteTests::pFH = NULL;
}