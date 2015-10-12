#include "stdafx.h"
#include "CppUnitTest.h"

#include <chrono>
#include <thread>

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(HotReloadingTests)
	{
		char buffer[2048];

	public:

		TEST_METHOD(FlatheadObjectShouldBeDefined)
		{
			Flathead *pFH = new Flathead();

			WriteToFile("lib/HotReload.js", "");

			pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);

			Assert::AreEqual("{}", buffer);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

			WriteToFile("lib/HotReload.js", "exports.value = {test: 42};");

			pFH->Tick(1.0f);

			pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);

			Assert::AreEqual("{\"value\":{\"test\":42}}", buffer);

			delete pFH;
		}

		TEST_METHOD(ShouldProvideUnloadFunctionForHotSwapping)
		{
			Flathead *pFH = new Flathead();

			bool unloaded = false;

			WriteToFile("lib/HotUnload.js", "var global = this; exports.value = this.myVar; module.unload = function () { global.UnloadCalled = true; }");

			pFH->Execute("require('./HotUnload').value;", unloaded);

			Assert::IsFalse(unloaded);

			std::this_thread::sleep_for(std::chrono::seconds(1));

			WriteToFile("lib/HotUnload.js", "exports.value = this.UnloadCalled;");

			pFH->Tick(1.0f);

			pFH->Execute("require('./HotUnload').value;", unloaded);

			Assert::IsTrue(unloaded);

			delete pFH;
		}

		TEST_METHOD(ShouldBeDisabledWhenConfiguredAsSuch)
		{
			bool reloaded = false;

			Configuration cfg;

			cfg.EnableHotReload(false);

			Flathead *pFH = new Flathead(cfg);

			WriteToFile("lib/DontReload.js", "exports.value = false;");

			pFH->Execute("require('./DontReload').value;", reloaded);

			Assert::IsFalse(reloaded);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

			WriteToFile("lib/DontReload.js", "exports.value = true;");

			pFH->Tick(1.0f);

			pFH->Execute("require('./DontReload').value;", reloaded);

			Assert::IsFalse(reloaded);

			delete pFH;
		}

		void WriteToFile(char *fileName, char *output)
		{
			FILE* file;

			if (fopen_s(&file, fileName, "w"))
			{
				Assert::Fail(L"Could not write to file.");
				return; 
			}

			fprintf(file, output);

			fclose(file);
		}
	};
}