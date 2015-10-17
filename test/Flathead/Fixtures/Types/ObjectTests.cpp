#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Object.h"
#include "Types/String.h"
#include "Types/Number.h"
#include "Types/Boolean.h"

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

		TEST_METHOD(ShouldBeAbleToSetAString)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);

			myObject->Set("myKey", "stringValue");

			Types::Value *myProperty = myObject->Get("myKey");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsString());

			Types::String *myString = (Types::String *)myProperty;

			Assert::IsNotNull(myString);

			Assert::IsTrue(myString->IsString());
			Assert::IsTrue(myString->Equals("stringValue"));

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetAnInteger)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);

			myObject->Set("myKey", 42);

			Types::Value *myProperty = myObject->Get("myKey");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsNumber());

			Types::Number *myNumber = (Types::Number *)myProperty;

			Assert::IsNotNull(myNumber);

			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetADouble)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);

			myObject->Set("myKey", 42.0);

			Types::Value *myProperty = myObject->Get("myKey");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsNumber());

			Types::Number *myNumber = (Types::Number *)myProperty;

			Assert::IsNotNull(myNumber);

			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetAFloat)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);

			myObject->Set("myKey", 42.0f);

			Types::Value *myProperty = myObject->Get("myKey");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsNumber());

			Types::Number *myNumber = (Types::Number *)myProperty;

			Assert::IsNotNull(myNumber);

			Assert::IsTrue(myNumber->IsNumber());
			Assert::AreEqual(42.0, (double)*myNumber);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetABoolean)
		{
			bool tmp;
			pFH->Execute("myObject = {test: 'value'};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);

			myObject->Set("myKey", true);

			Types::Value *myProperty = myObject->Get("myKey");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsBoolean());

			Types::Boolean *myBoolean = (Types::Boolean *)myProperty;

			Assert::IsNotNull(myBoolean);

			Assert::IsTrue(myBoolean->IsBoolean());
			Assert::IsTrue(*myBoolean);

			delete myProperty;
			delete myObject;
		}
	};
}