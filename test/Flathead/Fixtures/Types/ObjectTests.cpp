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
	class Sample
	{
	public:
		int value;
	};

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

		TEST_METHOD_INITIALIZE(MethodInitialize)
		{
			VoidDoSomethingCalled = false;
			IntDoSomethingCalled = false;
			BoolDoSomethingCalled = false;
			DoubleDoSomethingCalled = false;
			FloatDoSomethingCalled = false;
			PointerDoSomethingCalled = false;
		}

		static bool VoidDoSomethingCalled;
		static void VoidDoSomething(Types::CallbackInfo &args)
		{
			VoidDoSomethingCalled = true;
			return;
		}

		static bool IntDoSomethingCalled;
		static int IntDoSomething(Types::CallbackInfo &args)
		{
			IntDoSomethingCalled = true;
			Types::Number *num = (Types::Number *)args[0];
			return (int)*num;
		}

		static bool BoolDoSomethingCalled;
		static bool BoolDoSomething(Types::CallbackInfo &args)
		{
			BoolDoSomethingCalled = true;
			Types::Boolean *b = (Types::Boolean *)args[0];
			return *b;
		}

		static bool DoubleDoSomethingCalled;
		static double DoubleDoSomething(Types::CallbackInfo &args)
		{
			DoubleDoSomethingCalled = true;
			Types::Number *num = (Types::Number *)args[0];
			return (double)*num;
		}

		static bool FloatDoSomethingCalled;
		static float FloatDoSomething(Types::CallbackInfo &args)
		{
			FloatDoSomethingCalled = true;
			Types::Number *num = (Types::Number *)args[0];
			return (float)*num;
		}

		static bool PointerDoSomethingCalled;
		static void *PointerDoSomething(Types::CallbackInfo &args)
		{
			PointerDoSomethingCalled = true;
			Types::Number *num = (Types::Number *)args[0];
			return (void *)(int)(double)*num;
		}

		static bool StringDoSomethingCalled;
		static char *StringDoSomething(Types::CallbackInfo &args)
		{
			StringDoSomethingCalled = true;
			return "Test Value";
		}

		static bool WideStringDoSomethingCalled;
		static wchar_t *WideStringDoSomething(Types::CallbackInfo &args)
		{
			WideStringDoSomethingCalled = true;
			return L"Test Value";
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

		TEST_METHOD(ShouldBeAbleToGetFunctions)
		{
			bool tmp;
			pFH->Execute("myObject = {test: function () {}};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);
			Types::Value *myProperty = myObject->Get("test");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetVoidFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("voidCB", &ObjectTests::VoidDoSomething));
			Types::Value *myProperty = myObject->Get("voidCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.voidCB(42.0);", buffer);

			Assert::AreEqual("undefined", buffer);

			Assert::IsTrue(VoidDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetIntFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("intCB", &ObjectTests::IntDoSomething));
			Types::Value *myProperty = myObject->Get("intCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.intCB(42.0);", buffer);

			Assert::AreEqual("42", buffer);

			Assert::IsTrue(IntDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetBoolFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("boolCB", &ObjectTests::BoolDoSomething));
			Types::Value *myProperty = myObject->Get("boolCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.boolCB(42.0);", buffer);

			Assert::AreEqual("true", buffer);

			Assert::IsTrue(BoolDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetDoubleFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("doubleCB", &ObjectTests::DoubleDoSomething));
			Types::Value *myProperty = myObject->Get("doubleCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.doubleCB(42.0);", buffer);

			Assert::AreEqual("42", buffer);

			Assert::IsTrue(DoubleDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetFloatFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("floatCB", &ObjectTests::FloatDoSomething));
			Types::Value *myProperty = myObject->Get("floatCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.floatCB(42.0);", buffer);

			Assert::AreEqual("42", buffer);

			Assert::IsTrue(FloatDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetAStringFunction)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("stringCB", &ObjectTests::StringDoSomething));
			Types::Value *myProperty = myObject->Get("stringCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.stringCB(42.0);", buffer);

			Assert::AreEqual("Test Value", buffer);

			Assert::IsTrue(StringDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetAWideStringFunction)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("wideStringCB", &ObjectTests::WideStringDoSomething));
			Types::Value *myProperty = myObject->Get("wideStringCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.wideStringCB(42.0);", buffer);

			Assert::AreEqual("Test Value", buffer);

			Assert::IsTrue(WideStringDoSomethingCalled);

			delete myProperty;
			delete myObject;
		}

		TEST_METHOD(ShouldBeAbleToSetVoidPFunctions)
		{
			bool tmp;
			char buffer[128] = { 0 };
			pFH->Execute("myObject = {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsTrue(myObject->Set("voidPCB", &ObjectTests::PointerDoSomething));
			Types::Value *myProperty = myObject->Get("voidPCB");

			Assert::IsNotNull(myProperty);
			Assert::IsTrue(myProperty->IsFunction());

			Types::Function *myFunction = (Types::Function *)myProperty;

			Assert::IsNotNull(myFunction);

			Assert::IsTrue(myFunction->IsFunction());

			pFH->Execute("myObject.voidPCB(42.0);", buffer);

			Assert::AreEqual("42", buffer);

			Assert::IsTrue(PointerDoSomethingCalled);

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

		TEST_METHOD(ShouldBeAbleToSetAnObject)
		{
			Types::Object *pObject = Types::Object::New();

			pFH->Set("myVar", pObject);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsObject());

			delete pObject;
		}

		TEST_METHOD(ShouldBeAbleToExposeAGivenObject)
		{
			Sample *pSample = new Sample();
			pSample->value = 42;

			Types::Object *pObject = Types::Object::New("sampleObject", pSample);

			Types::Value *MyObjectValue = pFH->Get("sampleObject");

			Assert::IsNotNull(MyObjectValue);

			Types::Object *myObject = (Types::Object *)MyObjectValue;

			Assert::IsNotNull(myObject);
			Sample *pReference = (Sample *)myObject->GetReference();

			Assert::IsNotNull(pReference);
			Assert::AreEqual(pReference->value, pSample->value);

			delete pSample;
		}
	};

	bool ObjectTests::VoidDoSomethingCalled = false;
	bool ObjectTests::IntDoSomethingCalled = false;
	bool ObjectTests::BoolDoSomethingCalled = false;
	bool ObjectTests::DoubleDoSomethingCalled = false;
	bool ObjectTests::FloatDoSomethingCalled = false;
	bool ObjectTests::PointerDoSomethingCalled = false;
	bool ObjectTests::StringDoSomethingCalled = false;
	bool ObjectTests::WideStringDoSomethingCalled = false;
}