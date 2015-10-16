#include "stdafx.h"
#include "NumberIMPL.h"

#include "v8.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

NumberIMPL::NumberIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::Number>::Cast(_value));
}

NumberIMPL::operator double() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Number> numberValue = Handle<v8::Number>::New(g_CurrentVM, persisted_value);

	return numberValue->Value();
}

bool NumberIMPL::IsNumber() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Number> value = Handle<v8::Number>::New(g_CurrentVM, persisted_value);

	return value->IsNumber();
}

bool NumberIMPL::IsInt32() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Number> value = Handle<v8::Number>::New(g_CurrentVM, persisted_value);

	return value->IsInt32();
}

bool NumberIMPL::IsUint32() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Number> value = Handle<v8::Number>::New(g_CurrentVM, persisted_value);

	return value->IsUint32();
}
