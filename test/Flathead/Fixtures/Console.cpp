#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(ConsoleTests)
	{
		static Flathead *fh;
		char buffer[2048];

	public:
		TEST_CLASS_INITIALIZE(InitializeConsoleTests)
		{
			Configuration cfg;

			cfg.LoggingFn(TrackingLoggingFn);

			fh = new Flathead(cfg);
		}

		TEST_METHOD_INITIALIZE(InitializeConsoleTestsMethods)
		{
			ResetTracking();
		}

		TEST_METHOD(ShouldHaveAGlobalConsoleObject)
		{
			fh->Execute("console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeWritable)
		{
			fh->Execute("console = 42; console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeEnumerable)
		{
			bool result;

			fh->Execute("this.propertyIsEnumerable('console');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(ConsoleObjectShouldNotBeConfigurable)
		{
			fh->Execute("delete console; console;", buffer);

			Assert::AreEqual("[object Object]", buffer);

			fh->Execute("delete this.console; this.console;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeLogFunction)
		{
			fh->Execute("console.log;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeWarnFunction)
		{
			fh->Execute("console.warn;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeErrorFunction)
		{
			fh->Execute("console.error;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeInfoFunction)
		{
			fh->Execute("console.info;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveANativeAssertFunction)
		{
			fh->Execute("console.assert;", buffer);

			Assert::AreEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(ConsoleObjectShouldHaveAJSCountFunction)
		{
			fh->Execute("console.count;", buffer);

			Assert::AreNotEqual("function () { [native code] }", buffer);
		}

		TEST_METHOD(LogFunctionShouldHaveATypeOf0)
		{
			fh->Execute("console.log(\"test\");", buffer);

			Assert::AreEqual(0, g_Type);
		}

		TEST_METHOD(LogFunctionShouldPassValue)
		{
			fh->Execute("console.log(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(InfoFunctionShouldHaveATypeOf1)
		{
			fh->Execute("console.info(\"test\");", buffer);

			Assert::AreEqual(1, g_Type);
		}

		TEST_METHOD(InfoFunctionShouldPassValue)
		{
			fh->Execute("console.info(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(WarnFunctionShouldHaveATypeOf2)
		{
			fh->Execute("console.warn(\"test\");", buffer);

			Assert::AreEqual(2, g_Type);
		}

		TEST_METHOD(WarnFunctionShouldPassValue)
		{
			fh->Execute("console.warn(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(ErrorFunctionShouldHaveATypeOf3)
		{
			fh->Execute("console.error(\"test\");", buffer);

			Assert::AreEqual(3, g_Type);
		}

		TEST_METHOD(ErrorFunctionShouldPassValue)
		{
			fh->Execute("console.error(\"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(ShouldHaveCountFunction)
		{
			fh->Execute("console.log(typeof(console.count));", buffer);

			Assert::AreEqual("function", g_Buffer);
		}

		TEST_METHOD(LogShouldNotBeWritable)
		{
			fh->Execute("console.log = {}; console.log('testWritable');", buffer);

			Assert::AreEqual(0, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(InfoShouldNotBeWritable)
		{
			fh->Execute("console.info = {}; console.info('testWritable');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(WarnShouldNotBeWritable)
		{
			fh->Execute("console.warn = {}; console.warn('testWritable');", buffer);

			Assert::AreEqual(2, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(ErrorShouldNotBeWritable)
		{
			fh->Execute("console.error = {}; console.error('testWritable');", buffer);

			Assert::AreEqual(3, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(CountShouldAcceptASingleParameter)
		{
			int count = -1;

			fh->Execute("console.count.length;", count);

			Assert::AreEqual(1, count);
		}

		TEST_METHOD(CountShouldLogAMessageWithACounterStartingWith1)
		{
			fh->Execute("console.count('test');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("test: 1", g_Buffer);
		}

		TEST_METHOD(CountShouldNotBeBoundByScope)
		{
			fh->Execute("(function () {console.count('testScope');})(); {console.count('testScope');}", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testScope: 2", g_Buffer);
		}

		TEST_METHOD(CountShouldIncrementTheCounterWithEachCall)
		{
			fh->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 1", g_Buffer);

			fh->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 2", g_Buffer);

			fh->Execute("console.count('testCounter');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testCounter: 3", g_Buffer);
		}

		TEST_METHOD(CountShouldNotBeWritable)
		{
			fh->Execute("console.count = {}; console.count('testWritable');", buffer);

			Assert::AreEqual(1, g_Type);
			Assert::AreEqual("testWritable: 1", g_Buffer);
		}

		TEST_METHOD(AssertShouldNotBeWritable)
		{
			fh->Execute("console.assert = {}; console.assert(false, 'testWritable');", buffer);

			Assert::AreEqual(4, g_Type);
			Assert::AreEqual("testWritable", g_Buffer);
		}

		TEST_METHOD(AssertFunctionShouldHaveATypeOf4WhenAssertionIsFalse)
		{
			fh->Execute("console.assert(false, \"test\");", buffer);

			Assert::AreEqual(4, g_Type);
		}

		TEST_METHOD(AssertFunctionShouldPassValueWhenAssertionIsFalse)
		{
			fh->Execute("console.assert(false, \"test\");", buffer);

			Assert::AreEqual("test", g_Buffer);
		}

		TEST_METHOD(AssertFunctionShouldHaveATypeOfNeg1WhenAssertionIsTrue)
		{
			fh->Execute("console.assert(true, \"test\");", buffer);

			Assert::AreEqual(-1, g_Type);
		}

		TEST_METHOD(AssertFunctionShouldPassNothingWhenAssertionIsTrue)
		{
			fh->Execute("console.assert(true, \"test\");", buffer);

			Assert::AreEqual("", g_Buffer);
		}

		TEST_METHOD(EmptyAssertionShouldOutputError)
		{
			fh->Execute("console.assert();", buffer);

			Assert::AreEqual(4, g_Type);
			Assert::AreEqual("", g_Buffer);
		}

		TEST_METHOD(ConsoleShouldHaveTracePropertyDefined)
		{
			fh->Execute("typeof(console.trace);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(TraceShouldNotBeWritable)
		{
			fh->Execute("console.trace = {}; typeof(console.trace);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(TraceShouldOutputAStackTrace)
		{
			fh->Execute("console.trace();", buffer);

			Assert::AreEqual("Error\n    at Object.<anonymous> (lib/core/bootstrap.js:34:19)\n    at <anonymous>:1:9", g_Buffer);
		}
	};

	Flathead *ConsoleTests::fh = NULL;
}