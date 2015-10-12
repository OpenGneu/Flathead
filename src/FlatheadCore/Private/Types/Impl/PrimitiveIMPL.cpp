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

bool PrimitiveIMPL::IsObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsObject();
}

bool PrimitiveIMPL::IsBoolean() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsBoolean();
}

bool PrimitiveIMPL::IsString() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsString();
}

bool PrimitiveIMPL::IsNumber() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsNumber();
}

bool PrimitiveIMPL::IsFunction() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsFunction();
}

bool PrimitiveIMPL::IsArray() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsArray();
}

bool PrimitiveIMPL::IsBooleanObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsBooleanObject();
}

bool PrimitiveIMPL::IsDate() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsDate();
}

bool PrimitiveIMPL::IsPromise() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsPromise();
}

bool PrimitiveIMPL::IsRegExp() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsRegExp();
}

bool PrimitiveIMPL::IsNumberObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsNumberObject();
}

bool PrimitiveIMPL::IsStringObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsStringObject();
}

bool PrimitiveIMPL::IsSymbol() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsSymbol();
}

bool PrimitiveIMPL::IsInt32() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsInt32();
}

bool PrimitiveIMPL::IsUint32() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Value>::New(g_CurrentVM, persisted_value);

	return value->IsUint32();
}
