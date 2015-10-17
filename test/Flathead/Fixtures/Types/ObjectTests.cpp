#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Object.h"
#include "Types/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(ObjectTests), RequiresFlathead
	{
	public:
		TEST_CLASS_INITIALIZE(InitializeStringTests)
		{
			SetupFlathead();
		}

		TEST_CLASS_CLEANUP(CleanupStringTests)
		{
			CleanupFlathead();
		}

		TEST_METHOD(ShouldBeAbleToRetrieveAnObject)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsObject());

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);
			Assert::IsTrue(myObject->IsObject());

			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToGetValuesFromObjects)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);
			Types::Value *myProperty = myObject->Get("test");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsString());

			Types::String *myString = (Types::String *)myProperty;

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->IsString());
			Assert::IsTrue(myString->Equals("value"));

			delete myProperty;
			delete myObject;
		}
	};
}