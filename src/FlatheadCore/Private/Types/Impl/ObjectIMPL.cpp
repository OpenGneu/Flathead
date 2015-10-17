#include "stdafx.h"

#include "v8.h"
#include "ObjectIMPL.h"
#include "Types/Translate.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

ObjectIMPL::ObjectIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::Object>::Cast(_value));
}

bool ObjectIMPL::IsObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsObject();
}

bool ObjectIMPL::IsFunction() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsFunction();
}

bool ObjectIMPL::IsArray() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsArray();
}

bool ObjectIMPL::IsBooleanObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsBooleanObject();
}

bool ObjectIMPL::IsDate() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsDate();
}

bool ObjectIMPL::IsPromise() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsPromise();
}

bool ObjectIMPL::IsRegExp() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsRegExp();
}

bool ObjectIMPL::IsNumberObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsNumberObject();
}

bool ObjectIMPL::IsStringObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsStringObject();
}

bool ObjectIMPL::IsSymbol() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return value->IsSymbol();
}

Gneu::Types::Value *ObjectIMPL::Get(char *name) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	Local<v8::Value> result = obj->Get(v8::String::NewFromUtf8(g_CurrentVM, name));

	return Types::Translate::ToFlathead(result);
}

bool ObjectIMPL::Set(char *key, char *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::String::NewFromUtf8(g_CurrentVM, value));
}

bool ObjectIMPL::Set(char *key, double value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Number::New(g_CurrentVM, value));
}

bool ObjectIMPL::Set(char *key, int value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Integer::New(g_CurrentVM, value));
}

bool ObjectIMPL::Set(char *key, bool value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Object>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Boolean::New(g_CurrentVM, value));
}