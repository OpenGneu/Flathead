#include "stdafx.h"
#include "StringIMPL.h"

#include "v8.h"

using namespace Gneu::Types;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

StringIMPL::StringIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::String>::Cast(_value));
}

bool StringIMPL::IsString() const
{
	return true;
}

bool StringIMPL::Equals(wchar_t *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> compared = v8::String::NewFromTwoByte(g_CurrentVM, (uint16_t *)value);
	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	return stringValue->Equals(compared);
}

bool StringIMPL::StrictEquals(wchar_t *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> compared = v8::String::NewFromTwoByte(g_CurrentVM, (uint16_t *)value);
	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	return stringValue->StrictEquals(compared);
}

bool StringIMPL::Equals(char *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> compared = v8::String::NewFromUtf8(g_CurrentVM, value);
	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	return stringValue->Equals(compared);
}

bool StringIMPL::StrictEquals(char *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> compared = v8::String::NewFromUtf8(g_CurrentVM, value);
	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	return stringValue->StrictEquals(compared);
}

int StringIMPL::Length() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	return stringValue->Length();
}

void StringIMPL::UTF8Value(char *target) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	stringValue->WriteUtf8(target);
}

void StringIMPL::Value(wchar_t *target) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::String> stringValue = Handle<v8::String>::New(g_CurrentVM, persisted_value);

	stringValue->Write((uint16_t *)target);
}