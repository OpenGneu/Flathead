#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(ConsoleTests), RequiresFlathead
	{
		char buffer[2048];

	public:
		TEST_CLASS_INITIALIZE(InitializeConsoleTests)
		{
			SetupFlathead();
		}

		TEST_METHOD_INITIALIZE(InitializeConsoleTestsMethods)
		{
			ResetTracking();
		}

		TEST_CLASS_CLEANUP(CleanupConsoleTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldHaveAGlobalConsoleObject)
		{
			pFH->Execute("console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeWritable)
		{
			pFH->Execute("console = 42; console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeEnumerable)
		{
			bool result;

			pFH->Execute("this.propertyIsEnumerable('console');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeConfigurable)
		{
			pFH->Execute("delete console; console;", buffer);

			Assert::AreEqual("[object Object]", buffer);

			pFH->Execute("delete this.console; this.console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeLogFunction)
		{
			pFH->Execute("console.log;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeWarnFunction)
		{
			pFH->Execute("console.warn;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeErrorFunction)
		{
			pFH->Execute("console.error;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeInfoFunction)
		{
			pFH->Execute("console.info;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeAssertFunction)
		{
			pFH->Execute("console.assert;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveAJSCountFunction)
		{
			pFH->Execute("console.count;", buffer);

			Assert::AreNotEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(LogFunctionShouldHaveATypeOf0)
		{
			pFH->Execute("console.log(\"test\");", buffer);

			Assert::AreEqual(0, g_Type);
		}

		TEST_METHOD(LogFunctionShouldPassValue)
		{
			pFH->Execute("console.log(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(InfoFunctionShouldHaveATypeOf1)
		{
			pFH->Execute("console.info(\"test\");", buffer);

			Assert::AreEqual(1, g_Type);
		}

		TEST_METHOD(InfoFunctionShouldPassValue)
		{
			pFH->Execute("console.info(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(WarnFunctionShouldHaveATypeOf2)
		{
			pFH->Execute("console.warn(\"test\");", buffer);

			Assert::AreEqual(2, g_Type);
		}

		TEST_METHOD(WarnFunctionShouldPassValue)
		{
			pFH->Execute("console.warn(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(ErrorFunctionShouldHaveATypeOf3)
		{
			pFH->Execute("console.error(\"test\");", buffer);

			Assert::AreEqual(3, g_Type);
		}

		TEST_METHOD(ErrorFunctionShouldPassValue)
		{
			pFH->Execute("console.error(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(ShouldHaveCountFunction)
		{
			pFH->Execute("console.log(typeof(console.count));", buffer);

			Assert::AreEqual("function", g_Buffer);
		}

		TEST_METHOD(LogShouldNotBeWritable)
		{
			pFH->Execute("console.log = {}; console.log('testWritable');", buffer);

			Assert::AreEqual(0, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(InfoShouldNotBeWritable)
		{
			pFH->Execute("console.info = {}; console.info('testWritable');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(WarnShouldNotBeWritable)
		{
			pFH->Execute("console.warn = {}; console.warn('testWritable');", buffer);

			Assert::AreEqual(2, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(ErrorShouldNotBeWritable)
		{
			pFH->Execute("console.error = {}; console.error('testWritable');", buffer);

			Assert::AreEqual(3, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(CountShouldAcceptASingleParameter)
		{
			int count = -1;

			pFH->Execute("console.count.length;", count);

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(CountShouldLogAMessageWithACounterStartingWith1)
		{
			pFH->Execute("console.count('test');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("test: 1", g_Buffer);
		}

		TEST_METHOD(CountShouldNotBeBoundByScope)
		{
			pFH->Execute("(function () {console.count('testScope');})(); {console.count('testScope');}", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testScope: 2", g_Buffer);
		}

		TEST_METHOD(CountShouldIncrementTheCounterWithEachCall)
		{
			pFH->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 1", g_Buffer);

			pFH->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 2", g_Buffer);

			pFH->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 3", g_Buffer);
		}

		TEST_METHOD(CountShouldNotBeWritable)
		{
			pFH->Execute("console.count = {}; console.count('testWritable');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testWritable: 1", g_Buffer);
		}

		TEST_METHOD(AssertShouldNotBeWritable)
		{
			pFH->Execute("console.assert = {}; console.assert(false, 'testWritable');", buffer);

			Assert::AreEqual(4, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(AssertFunctionShouldHaveATypeOf4WhenAssertionIsFalse)
		{
			pFH->Execute("console.assert(false, \"test\");", buffer);

			Assert::AreEqual(4, g_Type);
		}

		TEST_METHOD(AssertFunctionShouldPassValueWhenAssertionIsFalse)
		{
			pFH->Execute("console.assert(false, \"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(AssertFunctionShouldHaveATypeOfNeg1WhenAssertionIsTrue)
		{
			pFH->Execute("console.assert(true, \"test\");", buffer);

			Assert::AreEqual(-1, g_Type);
		}

		TEST_METHOD(AssertFunctionShouldPassNothingWhenAssertionIsTrue)
		{
			pFH->Execute("console.assert(true, \"test\");", buffer);

			Assert::AreEqual("", g_Buffer);
		}

		TEST_METHOD(EmptyAssertionShouldOutputError)
		{
			pFH->Execute("console.assert();", buffer);

			Assert::AreEqual(4, g_Type);
			Assert::AreEqual("", g_Buffer);
		}

		TEST_METHOD(ConsoleShouldHaveTracePropertyDefined)
		{
			pFH->Execute("typeof(console.trace);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(TraceShouldNotBeWritable)
		{
			pFH->Execute("console.trace = {}; typeof(console.trace);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(TraceShouldOutputAStackTrace)
		{
			pFH->Execute("console.trace();", buffer);

			Assert::AreEqual("Error\n    at Object.<anonymous> (lib/core/bootstrap.js:34:19)\n    at <anonymous>:1:9", g_Buffer);
		}
	};
}