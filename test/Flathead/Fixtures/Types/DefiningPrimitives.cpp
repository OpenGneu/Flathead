#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "Types/Primitive.h"
#include "Types/Constants.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	namespace Types
	{
		TEST_CLASS(PrimitiveTests)
		{
			static Flathead *fh;
			char buffer[2048];

		public:
			TEST_CLASS_INITIALIZE(InitializePrimitiveTests)
			{
				Configuration cfg;

				cfg.LoggingFn(TrackingLoggingFn);

				fh = new Flathead(cfg);

				Assert::IsNotNull(fh);
			}

			TEST_METHOD(ShouldDeriveFromValue)
			{
				Primitive primitive;
				Value *pV = (Value *)&primitive;

				Assert::IsNotNull(pV);
			}

			TEST_METHOD(UndefinedShouldBeDefinedAsAPrimitive)
			{
				Primitive *primitive = (Primitive *)&Constants::Undefined;

				Assert::IsNotNull(primitive);
			}

			TEST_METHOD(NullShouldBeDefinedAsAPrimitive)
			{
				Primitive *primitive = (Primitive *)&Constants::Null;

				Assert::IsNotNull(primitive);
			}

			TEST_METHOD(UndefinedShouldKnowItIsUndefined)
			{
				Assert::IsTrue(Constants::Undefined.IsUndefined());
			}

			TEST_METHOD(UndefinedShouldKnowItIsNotNull)
			{
				Assert::IsFalse(Constants::Undefined.IsNull());
			}

			TEST_METHOD(NullShouldKnowItIsNull)
			{
				Assert::IsTrue(Constants::Null.IsNull());
			}

			TEST_METHOD(NullShouldKnowItIsNotUndefined)
			{
				Assert::IsFalse(Constants::Null.IsUndefined());
			}
		};

		Flathead *PrimitiveTests::fh = NULL;
	}
}