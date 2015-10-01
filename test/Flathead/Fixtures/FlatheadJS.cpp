#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(FlatheadJSTests)
	{
		static Flathead *pFH;

	public:
		TEST_CLASS_INITIALIZE(InitializeFlatheadJSTests)
		{
			pFH = new Flathead();
		}

		TEST_METHOD(FlatheadObjectShouldBeDefined)
		{
			char buffer[4096];

			pFH->Execute("flathead;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(FlatheadObjectShouldNotBeWritable)
		{
			char buffer[2048];

			pFH->Execute("flathead = 42; flathead;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(FlatheadObjectShouldNotBeEnumerable)
		{
			bool result;

			pFH->Execute("this.propertyIsEnumerable('flathead');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(FlatheadObjectShouldNotBeConfigurable)
		{
			char buffer[2048];

			pFH->Execute("delete flathead; flathead;", buffer);

			Assert::AreEqual("[object Object]", buffer);

			pFH->Execute("delete this.flathead; this.flathead;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(FlatheadObjectShouldHaveAVersionDefinedAsAString)
		{
			char buffer[2048];

			pFH->Execute("typeof(flathead.version);", buffer);

			Assert::AreEqual("string", buffer);
		}

		TEST_METHOD(FlatheadVersionObjectShouldNotBeWritable)
		{
			char buffer[2048];

			pFH->Execute("flathead.version = 42; typeof(flathead.version);", buffer);

			Assert::AreEqual("string", buffer);
		}

		TEST_METHOD(FlatheadVersionObjectShouldNotBeEnumerable)
		{
			bool result;

			pFH->Execute("flathead.propertyIsEnumerable('version');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(FlatheadVersionObjectShouldNotBeConfigurable)
		{
			char buffer[2048];

			pFH->Execute("delete flathead.version; typeof(flathead.version);", buffer);

			Assert::AreEqual("string", buffer);
		}
	};
	Flathead *FlatheadJSTests::pFH = NULL;
}