#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(FlatheadTests)
	{
	public:

		TEST_METHOD(ShouldHaveADefaultConstructor)
		{
			Flathead fh;
		}

		TEST_METHOD(ShouldHaveAConstructorTakingAConfigurationObject)
		{
			Configuration cfg;

			cfg.ShouldInitializeImmediately(false);

			Flathead fh(cfg);
		}

		TEST_METHOD(ShouldCreateADefaultConfigurationsObjectWhenCreatedWithoutOne)
		{
			Flathead fh;

			Assert::IsNotNull(fh.GetConfiguration());
		}

		TEST_METHOD(ShouldRetainACopyOfTheConfigurationObject)
		{
			Configuration cfg;

			cfg.ShouldInitializeImmediately(false);

			Flathead fh(cfg);

			Assert::IsNotNull(fh.GetConfiguration());
			Assert::AreNotEqual((uint64_t)&cfg, (uint64_t)fh.GetConfiguration());
		}
	};
}