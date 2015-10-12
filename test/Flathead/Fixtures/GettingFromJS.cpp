#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"
#include "Types/Value.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(GettingFromJSTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeConsoleTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupConsoleTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldHaveGetMethod)
		{
			pFH->Get("MyVar");
		}

		TEST_METHOD(GetMethodShouldReturnPointer)
		{
			Assert::IsNotNull(pFH->Get("v8"));
		}

		TEST_METHOD(UndefinedTypesShouldBeUndefined)
		{
			const Types::Value *pValue = pFH->Get("MyUndefinedVar");

			Assert::IsNotNull(pValue);
			Assert::IsTrue(pValue->IsUndefined());
		}

		TEST_METHOD(NullTypesShouldBeNull)
		{
			bool tmp;

			pFH->Execute("myNullVar = null;", tmp);

			const Types::Value *pValue = pFH->Get("myNullVar");

			Assert::IsNotNull(pValue);
			Assert::IsFalse(pValue->IsUndefined());
			Assert::IsTrue(pValue->IsNull());
		}
	};
}