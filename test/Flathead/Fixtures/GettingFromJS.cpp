#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "RequiresFlathead.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(GettingFromJSTests), RequiresFlathead
	{
	public:
		TEST_METHOD(ShouldHaveGetMethod)
		{
			pFH->Get("MyVar");
		}

		TEST_METHOD(GetMethodShouldReturnPointer)
		{
			Assert::IsNotNull(pFH->Get("MyVar"));
		}
	};
}