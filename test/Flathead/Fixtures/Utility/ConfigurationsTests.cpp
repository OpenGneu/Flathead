#include "stdafx.h"
#include "CppUnitTest.h"

#include "Utility/Configuration.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{		
	namespace Utility
	{
		TEST_CLASS(ConfigurationsTests)
		{
		public:

			TEST_METHOD(ShouldHaveADefaultConstructor)
			{
				Configuration cfg;
			}

			TEST_METHOD(ShouldHaveACopyConstructor)
			{
				Configuration cfg;

				cfg.Path("TestPath");

				Configuration *cfg2 = new Configuration(&cfg);

				Assert::AreEqual(cfg2->Path(), cfg.Path());

				delete cfg2;
			}

			TEST_METHOD(PathShouldDefaultToLibDirectory)
			{
				Configuration cfg;

				Assert::AreEqual("lib/", cfg.Path());
			}

			TEST_METHOD(PathShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::AreEqual("lib/", cfg.Path());
				cfg.Path("test");
				Assert::AreEqual("test", cfg.Path());
				cfg.Path("bravo");
				Assert::AreEqual("bravo", cfg.Path());
			}

			TEST_METHOD(HotReloadShouldDefaultToTrue)
			{
				Configuration cfg;

				Assert::IsTrue(cfg.EnableHotReload());
			}

			TEST_METHOD(HotReloadShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsTrue(cfg.EnableHotReload());
				cfg.EnableHotReload(false);
				Assert::IsFalse(cfg.EnableHotReload());
				cfg.EnableHotReload(true);
				Assert::IsTrue(cfg.EnableHotReload());
			}

			TEST_METHOD(ES6StagingShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableESStaging());
			}

			TEST_METHOD(ES6StagingShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableESStaging());
				cfg.EnableESStaging(true);
				Assert::IsTrue(cfg.EnableESStaging());
				cfg.EnableESStaging(false);
				Assert::IsFalse(cfg.EnableESStaging());
			}

			TEST_METHOD(HarmonyShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmony());
			}

			TEST_METHOD(HarmonyShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmony());
				cfg.EnableHarmony(true);
				Assert::IsTrue(cfg.EnableHarmony());
				cfg.EnableHarmony(false);
				Assert::IsFalse(cfg.EnableHarmony());
			}

			TEST_METHOD(HarmonyArraysShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyArrays());
			}

			TEST_METHOD(HarmonyArraysShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyArrays());
				cfg.EnableHarmonyArrays(true);
				Assert::IsTrue(cfg.EnableHarmonyArrays());
				cfg.EnableHarmonyArrays(false);
				Assert::IsFalse(cfg.EnableHarmonyArrays());
			}

			TEST_METHOD(HarmonyCollectionsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyCollections());
			}

			TEST_METHOD(HarmonyCollectionsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyCollections());
				cfg.EnableHarmonyCollections(true);
				Assert::IsTrue(cfg.EnableHarmonyCollections());
				cfg.EnableHarmonyCollections(false);
				Assert::IsFalse(cfg.EnableHarmonyCollections());
			}

			TEST_METHOD(HarmonyGeneratorsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyGenerators());
			}

			TEST_METHOD(HarmonyGeneratorsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyGenerators());
				cfg.EnableHarmonyGenerators(true);
				Assert::IsTrue(cfg.EnableHarmonyGenerators());
				cfg.EnableHarmonyGenerators(false);
				Assert::IsFalse(cfg.EnableHarmonyGenerators());
			}

			TEST_METHOD(HarmonyIterationShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyIteration());
			}

			TEST_METHOD(HarmonyIterationShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyIteration());
				cfg.EnableHarmonyIteration(true);
				Assert::IsTrue(cfg.EnableHarmonyIteration());
				cfg.EnableHarmonyIteration(false);
				Assert::IsFalse(cfg.EnableHarmonyIteration());
			}

			TEST_METHOD(HarmonyMathsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyMaths());
			}

			TEST_METHOD(HarmonyMathsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyMaths());
				cfg.EnableHarmonyMaths(true);
				Assert::IsTrue(cfg.EnableHarmonyMaths());
				cfg.EnableHarmonyMaths(false);
				Assert::IsFalse(cfg.EnableHarmonyMaths());
			}

			TEST_METHOD(HarmonyModulesShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyModules());
			}

			TEST_METHOD(HarmonyModulesShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyModules());
				cfg.EnableHarmonyModules(true);
				Assert::IsTrue(cfg.EnableHarmonyModules());
				cfg.EnableHarmonyModules(false);
				Assert::IsFalse(cfg.EnableHarmonyModules());
			}

			TEST_METHOD(HarmonyNumericLiteralsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyNumericLiterals());
			}

			TEST_METHOD(HarmonyNumericLiteralsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyNumericLiterals());
				cfg.EnableHarmonyNumericLiterals(true);
				Assert::IsTrue(cfg.EnableHarmonyNumericLiterals());
				cfg.EnableHarmonyNumericLiterals(false);
				Assert::IsFalse(cfg.EnableHarmonyNumericLiterals());
			}

			TEST_METHOD(HarmonyTypeOfShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyTypeOf());
			}

			TEST_METHOD(HarmonyTypeOfShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyTypeOf());
				cfg.EnableHarmonyTypeOf(true);
				Assert::IsTrue(cfg.EnableHarmonyTypeOf());
				cfg.EnableHarmonyTypeOf(false);
				Assert::IsFalse(cfg.EnableHarmonyTypeOf());
			}

			TEST_METHOD(HarmonyObservationShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyObservation());
			}

			TEST_METHOD(HarmonyObservationShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyObservation());
				cfg.EnableHarmonyObservation(true);
				Assert::IsTrue(cfg.EnableHarmonyObservation());
				cfg.EnableHarmonyObservation(false);
				Assert::IsFalse(cfg.EnableHarmonyObservation());
			}

			TEST_METHOD(HarmonyProxiesShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyProxies());
			}

			TEST_METHOD(HarmonyProxiesShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyProxies());
				cfg.EnableHarmonyProxies(true);
				Assert::IsTrue(cfg.EnableHarmonyProxies());
				cfg.EnableHarmonyProxies(false);
				Assert::IsFalse(cfg.EnableHarmonyProxies());
			}

			TEST_METHOD(HarmonyScopingShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyScoping());
			}

			TEST_METHOD(HarmonyScopingShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyScoping());
				cfg.EnableHarmonyScoping(true);
				Assert::IsTrue(cfg.EnableHarmonyScoping());
				cfg.EnableHarmonyScoping(false);
				Assert::IsFalse(cfg.EnableHarmonyScoping());
			}

			TEST_METHOD(HarmonyStringsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyStrings());
			}

			TEST_METHOD(HarmonyStringsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyStrings());
				cfg.EnableHarmonyStrings(true);
				Assert::IsTrue(cfg.EnableHarmonyStrings());
				cfg.EnableHarmonyStrings(false);
				Assert::IsFalse(cfg.EnableHarmonyStrings());
			}

			TEST_METHOD(HarmonySymbolsShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonySymbols());
			}

			TEST_METHOD(HarmonySymbolsShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonySymbols());
				cfg.EnableHarmonySymbols(true);
				Assert::IsTrue(cfg.EnableHarmonySymbols());
				cfg.EnableHarmonySymbols(false);
				Assert::IsFalse(cfg.EnableHarmonySymbols());
			}

			TEST_METHOD(ShouldInitializeImmediatelyShouldDefaultToTrue)
			{
				Configuration cfg;

				Assert::IsTrue(cfg.ShouldInitializeImmediately());
			}

			TEST_METHOD(ShouldInitializeImmediatelyShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsTrue(cfg.ShouldInitializeImmediately());
				cfg.ShouldInitializeImmediately(false);
				Assert::IsFalse(cfg.ShouldInitializeImmediately());
				cfg.ShouldInitializeImmediately(true);
				Assert::IsTrue(cfg.ShouldInitializeImmediately());
			}

			TEST_METHOD(EnableHarmonyDestructuringShouldDefaultToFalse)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyDestructuring());
			}

			TEST_METHOD(EnableHarmonyDestructuringShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::IsFalse(cfg.EnableHarmonyDestructuring());
				cfg.EnableHarmonyDestructuring(true);
				Assert::IsTrue(cfg.EnableHarmonyDestructuring());
				cfg.EnableHarmonyDestructuring(false);
				Assert::IsFalse(cfg.EnableHarmonyDestructuring());
			}

			TEST_METHOD(BootstrapShouldDefaultToDEFAULTBOOTSTRAP)
			{
				Configuration cfg;

				Assert::AreEqual("lib/core/bootstrap.js", cfg.Bootstrap());
			}

			TEST_METHOD(BootstrapShouldBeAbleToBeChanged)
			{
				Configuration cfg;

				Assert::AreEqual("lib/core/bootstrap.js", cfg.Bootstrap());
				cfg.Bootstrap("./bootstrap.js");
				Assert::AreEqual("./bootstrap.js", cfg.Bootstrap());
			}

			TEST_METHOD(FunctionChainingShouldWorkOnAllSetters)
			{
				Configuration cfg;

				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableESStaging(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmony(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyArrays(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyCollections(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyGenerators(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyIteration(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyMaths(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyModules(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyNumericLiterals(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyObservation(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyProxies(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyScoping(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyStrings(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonySymbols(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyDestructuring(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHarmonyTypeOf(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.EnableHotReload(true));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.LoggingFn(NULL));
				Assert::AreEqual((uint64_t)&cfg, (uint64_t)cfg.Path("test"));
			}
		};
	}
}