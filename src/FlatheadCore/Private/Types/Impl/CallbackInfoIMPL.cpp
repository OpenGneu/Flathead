#include "stdafx.h"

#include "v8.h"
#include "CallbackInfoIMPL.h"
#include "Types/Value.h"
#include "Types/Translate.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

using namespace Gneu::Types;
using namespace v8;

CallbackInfoIMPL::CallbackInfoIMPL(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	arguments = &args;
}

Gneu::Types::Value *CallbackInfoIMPL::operator[](int ndx) const
{
	return Translate::ToFlathead((*arguments)[ndx]);
}