#include "stdafx.h"
#include "CppUnitTest.h"

#include <chrono>
#include <thread>

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(HotReloadingTests)
	{
		static Flathead *pFH;

	public:
		TEST_CLASS_INITIALIZE(InitializeHotReloadingTests)
		{
			pFH = new Flathead();
		}

		TEST_METHOD(FlatheadObjectShouldBeDefined)
		{
			char buffer[2048];
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

			WriteToFile("lib/HotReload.js", "var global = this; exports.value = this.myVar; module.unload = function () { global.unloaded = true; }");

			pFH->Execute("require('./HotReload').value;", unloaded);

			Assert::IsFalse(unloaded);

			std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

			WriteToFile("lib/HotReload.js", "exports.value = this.unloaded;");

			pFH->Tick(1.0f);

			pFH->Execute("require('./HotReload').value;", unloaded);

			Assert::IsTrue(unloaded);
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

	Flathead *HotReloadingTests::pFH = NULL;
}