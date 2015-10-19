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

		TEST_METHOD(ShouldTrapMissingBootstrapAtInitialization)
		{
			bool exceptionThrown = false;

			Configuration cfg;
			cfg.Bootstrap("lib/missingFile.js");

			try
			{
				Flathead fh(cfg);
			}
			catch (int ex) // TODO: Index to be defined
			{
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(ShouldTrapEmptyBootstrapAtInitialization)
		{
			bool exceptionThrown = false;

			Configuration cfg;
			cfg.Bootstrap("lib/emptyBootstrap.js");

			try
			{
				Flathead fh(cfg);
			}
			catch (int ex) // TODO: Index to be defined
			{
				exceptionThrown = true;
			}

			Assert::IsTrue(exceptionThrown);
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