#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(V8FlagsTests)
	{
	public:
		TEST_METHOD(StrictModeFlagOff)
		{
			Flathead fh;
			bool result;

			fh.Execute("(function() { return !this; })();", result);

			Assert::IsFalse(result);
		}

		TEST_METHOD(StrictModeFlagOn)
		{
			Configuration cfg;

			cfg.AlwaysStrict(true);

			Flathead fh(cfg);
			bool result;

			fh.Execute("(function() { return !this; })();", result);

			Assert::IsTrue(result);
		}
	};
}