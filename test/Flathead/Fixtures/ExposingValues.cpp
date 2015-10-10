#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "Types/Value.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	namespace Types
	{
		TEST_CLASS(ValueTests)
		{
			static Flathead *fh;
			char buffer[2048];

		public:
			TEST_CLASS_INITIALIZE(InitializeValueTests)
			{
				Configuration cfg;

				cfg.LoggingFn(TrackingLoggingFn);

				fh = new Flathead(cfg);

				Assert::IsNotNull(fh);
			}

			TEST_METHOD(ShouldHaveIsArrayMethod)
			{
				Value b;

				Assert::IsFalse(b.IsArray());
			}

			TEST_METHOD(ShouldHaveIsBooleanMethod)
			{
				Value b;

				Assert::IsFalse(b.IsBoolean());
			}

			TEST_METHOD(ShouldHaveIsBooleanObjectMethod)
			{
				Value b;

				Assert::IsFalse(b.IsBooleanObject());
			}

			TEST_METHOD(ShouldHaveIsDateMethod)
			{
				Value b;

				Assert::IsFalse(b.IsDate());
			}

			TEST_METHOD(ShouldHaveIsExternalMethod)
			{
				Value b;

				Assert::IsFalse(b.IsExternal());
			}

			TEST_METHOD(ShouldHaveIsFalseMethod)
			{
				Value b;

				Assert::IsTrue(b.IsFalse());
			}

			TEST_METHOD(ShouldHaveIsFunctionMethod)
			{
				Value b;

				Assert::IsFalse(b.IsFunction());
			}

			TEST_METHOD(ShouldHaveIsInt32Method)
			{
				Value b;

				Assert::IsFalse(b.IsInt32());
			}

			TEST_METHOD(ShouldHaveIsNativeErrorMethod)
			{
				Value b;

				Assert::IsFalse(b.IsNativeError());
			}

			TEST_METHOD(ShouldHaveIsNullMethod)
			{
				Value b;

				Assert::IsFalse(b.IsNull());
			}

			TEST_METHOD(ShouldHaveIsNumberMethod)
			{
				Value b;

				Assert::IsFalse(b.IsNumber());
			}

			TEST_METHOD(ShouldHaveIsNumberObjectMethod)
			{
				Value b;

				Assert::IsFalse(b.IsNumberObject());
			}

			TEST_METHOD(ShouldHaveIsObjectMethod)
			{
				Value b;

				Assert::IsFalse(b.IsObject());
			}

			TEST_METHOD(ShouldHaveIsRegExpMethod)
			{
				Value b;

				Assert::IsFalse(b.IsRegExp());
			}

			TEST_METHOD(ShouldHaveIsStringMethod)
			{
				Value b;

				Assert::IsFalse(b.IsString());
			}

			TEST_METHOD(ShouldHaveIsStringObjectMethod)
			{
				Value b;

				Assert::IsFalse(b.IsStringObject());
			}

			TEST_METHOD(ShouldHaveIsTrueMethod)
			{
				Value b;

				Assert::IsFalse(b.IsTrue());
			}

			TEST_METHOD(ShouldHaveIsUint32Method)
			{
				Value b;

				Assert::IsFalse(b.IsUint32());
			}

			TEST_METHOD(ShouldHaveIsUndefinedMethod)
			{
				Value b;

				Assert::IsTrue(b.IsUndefined());
			}
		}; 
		
		Flathead *ValueTests::fh = NULL;
	}
}