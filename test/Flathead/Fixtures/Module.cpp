#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(ModuleTests), RequiresFlathead
	{
		char buffer[2048];

	public:

		TEST_CLASS_INITIALIZE(InitializeModuleTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupModuleTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(RequireFunctionShouldBeDefined)
		{
			pFH->Execute("typeof(require);", buffer);

			Assert::AreEqual("function", buffer);
		}

		TEST_METHOD(ModuleObjectShouldBeDefined)
		{
			pFH->Execute("typeof(module);", buffer);

			Assert::AreEqual("object", buffer);
		}

		TEST_METHOD(ExportsObjectShouldBeDefined)
		{
			pFH->Execute("typeof(module);", buffer);

			Assert::AreEqual("object", buffer);
		}

		TEST_METHOD(ExportsObjectShouldBeAReferenceToModule_Exports)
		{
			pFH->Execute("module.exports.test=42; exports.test;", buffer);
			Assert::AreEqual("42", buffer);

			pFH->Execute("exports.test2=42; module.exports.test2;", buffer);
			Assert::AreEqual("42", buffer);
		}

		TEST_METHOD(ShouldBeAbleToRequireAModuleByRelativePath)
		{
			pFH->Execute("var meaning = require('./sampleModule'); meaning.meaningOfLife;", buffer);
			Assert::AreEqual("42", buffer);
		}

		TEST_METHOD(ShouldBeAbleToRequireAJSONFileByRelativePath)
		{
			pFH->Execute("var meaning = require('./sampleJSON.json'); meaning.meaningOfLife;", buffer);
			Assert::AreEqual("42", buffer);
		}
	};
}