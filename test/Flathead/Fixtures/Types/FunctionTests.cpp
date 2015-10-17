#include "stdafx.h"
#include "CppUnitTest.h"

#include "Flathead.h"
#include "../RequiresFlathead.h"

#include "Types/Number.h"
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
			return 0;
		}

		static bool BoolDoSomethingCalled;
		static bool BoolDoSomething(Types::CallbackInfo &args)
		{
			BoolDoSomethingCalled = true;
			return false;
		}

		static bool DoubleDoSomethingCalled;
		static double DoubleDoSomething(Types::CallbackInfo &args)
		{
			DoubleDoSomethingCalled = true;
			return 42.0;
		}

		static bool FloatDoSomethingCalled;
		static float FloatDoSomething(Types::CallbackInfo &args)
		{
			FloatDoSomethingCalled = true;
			return 42.0f;
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
			bool tmp;
			pFH->Set("myFunc", &FunctionTests::VoidDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAnIntFunction)
		{
			bool tmp;
			pFH->Set("myFunc", &FunctionTests::IntDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetABoolFunction)
		{
			bool tmp;
			pFH->Set("myFunc", &FunctionTests::BoolDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetADoubleFunction)
		{
			bool tmp;
			pFH->Set("myFunc", &FunctionTests::DoubleDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

			delete myFunc;
		}

		TEST_METHOD(ShouldBeAbleToSetAFloatFunction)
		{
			bool tmp;
			pFH->Set("myFunc", &FunctionTests::FloatDoSomething);

			Types::Value *MyObjectValue = pFH->Get("myFunc");

			Assert::IsNotNull(MyObjectValue);
			Assert::IsTrue(MyObjectValue->IsFunction());

			Types::Function *myFunc = (Types::Function *)MyObjectValue;

			Assert::IsNotNull(myFunc);
			Assert::IsTrue(myFunc->IsFunction());

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
