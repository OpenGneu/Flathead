#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(V8JSTests)
	{
		static Flathead *pFH;
		char buffer[2048];

	public:
		TEST_CLASS_INITIALIZE(InitializeV8JSTests)
		{
			pFH = new Flathead();
		}

		TEST_CLASS_CLEANUP(CleanupV8JSTests)
		{
			delete pFH;
		}

		TEST_METHOD(V8ObjectShouldBeDefined)
		{
			pFH->Execute("v8;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(V8ObjectShouldNotBeWritable)
		{
			pFH->Execute("v8 = 42; v8;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(V8ObjectShouldNotBeEnumerable)
		{
			bool result;

			pFH->Execute("this.propertyIsEnumerable('v8');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(V8ObjectShouldNotBeConfigurable)
		{
			pFH->Execute("delete v8; v8;", buffer);

			Assert::AreEqual("[object Object]", buffer);

			pFH->Execute("delete this.v8; this.v8;", buffer);

			Assert::AreEqual("[object Object]", buffer);
		}

		TEST_METHOD(V8ObjectShouldHaveAVersionDefinedAsAString)
		{
			pFH->Execute("typeof(v8.version);", buffer);

			Assert::AreEqual("string", buffer);
		}

		TEST_METHOD(V8VersionObjectShouldNotBeWritable)
		{
			pFH->Execute("v8.version = 42; typeof(v8.version);", buffer);

			Assert::AreEqual("string", buffer);
		}

		TEST_METHOD(V8VersionObjectShouldNotBeEnumerable)
		{
			bool result;

			pFH->Execute("v8.propertyIsEnumerable('version');", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(V8VersionObjectShouldNotBeConfigurable)
		{
			pFH->Execute("delete v8.version; typeof(v8.version);", buffer);

			Assert::AreEqual("string", buffer);
		}
	};

	Flathead * V8JSTests::pFH = NULL;
}