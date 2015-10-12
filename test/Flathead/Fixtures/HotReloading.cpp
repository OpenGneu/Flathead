#include "stdafx.h"
#include "CppUnitTest.h"

#include <chrono>
#include <thread>

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(HotReloadingTests), RequiresFlathead
	{
		char buffer[2048];

	public:
		TEST_CLASS_INITIALIZE(InitializeHotReloadingTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupHotReloadingTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(FlatheadObjectShouldBeDefined)
		{
			WriteToFile("lib/HotReload.js", "");

			pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);

			Assert::AreEqual("{}", buffer);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

			WriteToFile("lib/HotReload.js", "exports.value = {test: 42};");

			pFH->Tick(1.0f);

			pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);

			Assert::AreEqual("{\"value\":{\"test\":42}}", buffer);
		}

		TEST_METHOD(ShouldProvideUnloadFunctionForHotSwapping)
		{
			bool unloaded = false;

			WriteToFile("lib/HotUnload.js", "var global = this; exports.value = this.myVar; module.unload = function () { global.unloaded = true; }");

			pFH->Execute("require('./HotUnload').value;", unloaded);

			Assert::IsFalse(unloaded);

			std::this_thread::sleep_for(std::chrono::seconds(1));

			WriteToFile("lib/HotUnload.js", "exports.value = this.unloaded;");

			pFH->Tick(1.0f);

			pFH->Execute("require('./HotUnload').value;", unloaded);

			Assert::IsTrue(unloaded);
		}

		TEST_METHOD(ShouldBeDisabledWhenConfiguredAsSuch)
		{
			bool unloaded = false;

			Configuration cfg;

			cfg.EnableHotReload(false);

			Flathead *fh = new Flathead(cfg);

			WriteToFile("lib/DontReload.js", "var global = this; exports.value = this.myVar; module.unload = function () { global.unloaded = true; }");

			pFH->Execute("require('./DontReload').value;", unloaded);

			Assert::IsFalse(unloaded);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

			WriteToFile("lib/DontReload.js", "exports.value = this.unloaded;");

			pFH->Tick(1.0f);

			pFH->Execute("require('./DontReload').value;", unloaded);

			Assert::IsFalse(unloaded);
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