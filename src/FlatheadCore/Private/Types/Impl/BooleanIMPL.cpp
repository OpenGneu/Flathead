#include "stdafx.h"

#include "v8.h"
#include "BooleanIMPL.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

BooleanIMPL::BooleanIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::Boolean>::Cast(_value));
}

BooleanIMPL::BooleanIMPL(bool _value)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	persisted_value.Reset(g_CurrentVM, v8::Boolean::New(g_CurrentVM, _value));
}

BooleanIMPL::operator bool() const
{
	Isolate::Scope isolate_scope(g_CurrentVM); 
	HandleScope handle_scope(g_CurrentVM); 
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext); 
	Context::Scope context_scope(context);

	Local<v8::Boolean> boolValue = Handle<v8::Boolean>::New(g_CurrentVM, persisted_value);

	return boolValue->Value();
}

bool BooleanIMPL::IsBoolean() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Boolean> boolValue = Handle<v8::Boolean>::New(g_CurrentVM, persisted_value);

	return boolValue->IsBoolean();
}