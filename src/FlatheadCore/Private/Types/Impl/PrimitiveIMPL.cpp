#include "stdafx.h"
#include "PrimitiveIMPL.h"

#include "v8.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

PrimitiveIMPL::PrimitiveIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::Boolean>::Cast(_value));
}

bool PrimitiveIMPL::IsUndefined() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsUndefined();
}

bool PrimitiveIMPL::IsNull() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsNull();
}