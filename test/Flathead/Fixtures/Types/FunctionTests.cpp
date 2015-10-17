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
	};

	bool FunctionTests::VoidDoSomethingCalled = false;
	bool FunctionTests::IntDoSomethingCalled = false;
	bool FunctionTests::BoolDoSomethingCalled = false;
	bool FunctionTests::DoubleDoSomethingCalled = false;
	bool FunctionTests::FloatDoSomethingCalled = false;
	bool FunctionTests::PointerDoSomethingCalled = false;
}
