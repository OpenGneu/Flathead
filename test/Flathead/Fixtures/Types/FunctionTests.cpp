#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Number.h"
#include "Types/Boolean.h"
#include "Types/Function.h"
#include "Types/CallbackInfo.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Gneu
{
	TEST_CLASS(FunctionTests), RequiresFlathead
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

		TEST_METHOD(ShouldBeAbleToRetrieveAFunction)
		{
			bool tmp;
			pFH->Execute("myFunc = function () {};", tmp);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAVoidFunction)
		{
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::VoidDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(42.0);", buffer);

			Assert::AreEqual("undefined", buffer);

			Assert::IsTrue(VoidDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAnIntFunction)
		{
			int result;
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::IntDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(42);", result);

			Assert::AreEqual(42, result);

			Assert::IsTrue(IntDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetABoolFunction)
		{
			bool result;
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::BoolDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(false);", result);

			Assert::IsFalse(result);

			Assert::IsTrue(BoolDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetADoubleFunction)
		{
			float result;
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::DoubleDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(42.0);", result);

			Assert::AreEqual(42.0f, result);

			Assert::IsTrue(DoubleDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAFloatFunction)
		{
			float result;
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::FloatDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(42.0);", result);

			Assert::AreEqual(42.0f, result);

			Assert::IsTrue(FloatDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAPointerFunction)
		{
			int addr;
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::PointerDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(420000);", addr);

			Assert::AreEqual(420000, addr);

			Assert::IsTrue(PointerDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAStringFunction)
		{
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::StringDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(420000);", buffer);

			Assert::AreEqual("Test Value", buffer);

			Assert::IsTrue(StringDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAWideStringFunction)
		{
			char buffer[128] = { 0 };
			pFH->Set("myFunc", &FunctionTests::WideStringDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			pFH->Execute("myFunc;", buffer);

			Assert::AreEqual("function myFunc() { [native code] }", buffer);

			pFH->Execute("myFunc(420000);", buffer);

			Assert::AreEqual("Test Value", buffer);

			Assert::IsTrue(WideStringDoSomethingCalled);

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAVoidFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::VoidDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}

		TEST_METHOD(ShouldBeAbleToSetAnIntFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::IntDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}

		TEST_METHOD(ShouldBeAbleToSetAnBoolFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::BoolDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}

		TEST_METHOD(ShouldBeAbleToSetADoubleFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::DoubleDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}

		TEST_METHOD(ShouldBeAbleToSetAFloatFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::FloatDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}

		TEST_METHOD(ShouldBeAbleToSetAVoidPointerFunctionFromFunctionType)
		{
			Types::Function *pFn = Types::Function::New(&FunctionTests::PointerDoSomething);

			pFH->Set("myVar", pFn);

			Types::Value *myReturnValue = pFH->Get("myVar");

			Assert::IsNotNull(myReturnValue);
			Assert::IsTrue(myReturnValue->IsFunction());

			delete pFn;
		}
	};

	bool FunctionTests::VoidDoSomethingCalled = false;
	bool FunctionTests::IntDoSomethingCalled = false;
	bool FunctionTests::BoolDoSomethingCalled = false;
	bool FunctionTests::DoubleDoSomethingCalled = false;
	bool FunctionTests::FloatDoSomethingCalled = false;
	bool FunctionTests::PointerDoSomethingCalled = false;
	bool FunctionTests::StringDoSomethingCalled = false;
	bool FunctionTests::WideStringDoSomethingCalled = false;
}
