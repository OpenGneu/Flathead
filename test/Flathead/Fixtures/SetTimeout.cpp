#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(SetTimeoutTests)
	{
		static Flathead *pFH;
		char buffer[2048];

	public:
		TEST_CLASS_INITIALIZE(InitializeSetTimeoutTests)
		{
			Configuration cfg;

			cfg.LoggingFn(TrackingLoggingFn);

			pFH = new Flathead(cfg);
		}

		TEST_CLASS_CLEANUP(CleanupSetTimeoutTests)
		{
			delete pFH;
		}

		TEST_METHOD_INITIALIZE(InitializeSetTimeoutMethodTests)
		{
			ResetTracking();
		}

		TEST_METHOD(SetTimeoutFunctionShouldBeDefined)
		{
			pFH->Execute("typeof(setTimeout);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(SetTimeoutFunctionShouldExpectTwoParameters)
		{
			int count;

			pFH->Execute("setTimeout.length;", count);

			Assert::AreEqual(2, count);
		}

		TEST_METHOD(ClearTimeoutFunctionShouldBeDefined)
		{
			pFH->Execute("typeof(clearTimeout);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(ClearTimeoutFunctionShouldExpectOneParameters)
		{
			int count;

			pFH->Execute("clearTimeout.length;", count);

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(SetIntervalFunctionShouldBeDefined)
		{
			pFH->Execute("typeof(setInterval);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(SetIntervalFunctionShouldExpectTwoParameters)
		{
			int count;

			pFH->Execute("setTimeout.length;", count);

			Assert::AreEqual(2, count);
		}

		TEST_METHOD(ClearIntervalFunctionShouldBeDefined)
		{
			pFH->Execute("typeof(clearInterval);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(ClearIntervalFunctionShouldExpectOneParameters)
		{
			int count;

			pFH->Execute("clearInterval.length;", count);

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(TimeoutShouldExecuteMethodWhenTickUpdatedAppropriately)
		{
			pFH->Execute("var timeout = 0;", buffer);
			pFH->Execute("setTimeout(function () { timeout++; }, 250);", buffer);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Execute("timeout;", buffer);
			Assert::AreEqual("1", buffer);
		}

		TEST_METHOD(TimeoutShouldExecuteOnce)
		{
			pFH->Execute("var timeout = 0;", buffer);
			pFH->Execute("setTimeout(function () { timeout++; }, 250);", buffer);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Execute("timeout;", buffer);
			Assert::AreEqual("1", buffer);
		}

		TEST_METHOD(IntervalShouldExecuteMethodWhenTickUpdatedAppropriately)
		{
			pFH->Execute("var interval1 = 0;", buffer);
			pFH->Execute("setInterval(function () { interval1++; }, 200);", buffer);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Execute("interval1;", buffer);
			Assert::AreEqual("1", buffer);
		}

		TEST_METHOD(IntervalShouldExecuteUntilDisabled)
		{
			pFH->Execute("var interval2 = 0;", buffer);
			pFH->Execute("setInterval(function () { interval2++; }, 200);", buffer);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Tick(0.10f);
			pFH->Tick(0.10f);

			pFH->Execute("interval2;", buffer);
			Assert::AreEqual("5", buffer);
		}
	};

	Flathead *SetTimeoutTests::pFH = NULL;
}