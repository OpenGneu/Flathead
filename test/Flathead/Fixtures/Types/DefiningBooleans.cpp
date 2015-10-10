#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "Types/Boolean.h"
#include "Types/Constants.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	namespace Types
	{
		TEST_CLASS(BooleanTests)
		{
			static Flathead *fh;
			char buffer[2048];

		public:
			TEST_CLASS_INITIALIZE(InitializeBooleanTests)
			{
				Configuration cfg;

				cfg.LoggingFn(TrackingLoggingFn);

				fh = new Flathead(cfg);

				Assert::IsNotNull(fh);
			}

			TEST_METHOD(ShouldHaveAValue)
			{
				Boolean bTrue(true);
				Boolean bFalse(false);

				Assert::IsTrue(bTrue.Value());
				Assert::IsFalse(bFalse.Value());
			}

			TEST_METHOD(ShouldKnowItIsABoolean)
			{
				Boolean bTrue(true);
				Boolean bFalse(false);

				Assert::IsTrue(bTrue.IsBoolean());
				Assert::IsTrue(bFalse.IsBoolean());
			}

			TEST_METHOD(ShouldImplicitlyConvertToBoolean)
			{
				Boolean bTrue(true);
				Boolean bFalse(false);

				Assert::IsTrue(bTrue);
				Assert::IsFalse(bFalse);
			}

			TEST_METHOD(TrueConstantShouldBeDefined)
			{
				Boolean *boolean = (Boolean *)&Constants::True;

				Assert::IsNotNull(boolean);
			}

			TEST_METHOD(TrueConstantShouldKnowItIsABoolean)
			{
				Assert::IsTrue(Constants::True.IsBoolean());
			}

			TEST_METHOD(TrueConstantShouldBeTrue)
			{
				Assert::IsTrue(Constants::True);
			}

			TEST_METHOD(FalseConstantShouldBeDefined)
			{
				Boolean *boolean = (Boolean *)&Constants::False;

				Assert::IsNotNull(boolean);
			}

			TEST_METHOD(FalseConstantShouldKnowItIsABoolean)
			{
				Assert::IsTrue(Constants::False.IsBoolean());
			}

			TEST_METHOD(FalseConstantShouldBeTrue)
			{
				Assert::IsFalse(Constants::False);
			}

			TEST_METHOD(EqualityShouldWork)
			{
				Boolean bTrue1(true);
				Boolean bTrue2(true);

				Boolean bFalse1(false);
				Boolean bFalse2(false);

				Assert::IsTrue(bTrue1 == bTrue2);
				Assert::IsTrue(bTrue2 == bTrue1);

				Assert::IsTrue(bFalse1 == bFalse2);
				Assert::IsTrue(bFalse2 == bFalse1);

				Assert::IsTrue(bTrue1 != bFalse1);
				Assert::IsTrue(bTrue2 != bFalse1);

				Assert::IsTrue(bTrue1 != bFalse2);
				Assert::IsTrue(bTrue2 != bFalse2);

				Assert::IsTrue(bFalse1 != bTrue1);
				Assert::IsTrue(bFalse2 != bTrue1);

				Assert::IsTrue(bFalse1 != bTrue2);
				Assert::IsTrue(bFalse2 != bTrue2);
			}
		};

		Flathead *BooleanTests::fh = NULL;
	}
}