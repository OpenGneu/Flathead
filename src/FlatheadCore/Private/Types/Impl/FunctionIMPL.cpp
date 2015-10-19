#include "stdafx.h"

#include "v8.h"
#include "FunctionIMPL.h"
#include "Types/Translate.h"
#include "Private/Interfaces/CallbackInterfaces.h"

using namespace Gneu::Types;
using namespace Gneu::Interfaces;
using namespace v8;

extern Isolate *g_CurrentVM;
extern Persistent<Context> g_GlobalContext;

FunctionIMPL::FunctionIMPL(v8::Handle<v8::Value> _value)
{
	persisted_value.Reset(g_CurrentVM, v8::Handle<v8::Function>::Cast(_value));
}

FunctionIMPL::FunctionIMPL(VoidFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::VoidCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(IntFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::IntCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(BoolFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::BoolCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(VoidPFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::VoidPointerCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(DoubleFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::DoubleCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(FloatFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::FloatCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

bool FunctionIMPL::IsObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsObject();
}

bool FunctionIMPL::IsFunction() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsFunction();
}

bool FunctionIMPL::IsArray() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsArray();
}

bool FunctionIMPL::IsBooleanObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsBooleanObject();
}

bool FunctionIMPL::IsDate() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsDate();
}

bool FunctionIMPL::IsPromise() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsPromise();
}

bool FunctionIMPL::IsRegExp() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsRegExp();
}

bool FunctionIMPL::IsNumberObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsNumberObject();
}

bool FunctionIMPL::IsStringObject() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsStringObject();
}

bool FunctionIMPL::IsSymbol() const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Value> value = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return value->IsSymbol();
}

Gneu::Types::Value *FunctionIMPL::Get(char *name) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	Local<v8::Value> result = obj->Get(v8::String::NewFromUtf8(g_CurrentVM, name));

	return Types::Translate::ToFlathead(result);
}

bool FunctionIMPL::Set(char *key, char *value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::String::NewFromUtf8(g_CurrentVM, value));
}

bool FunctionIMPL::Set(char *key, double value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Number::New(g_CurrentVM, value));
}

bool FunctionIMPL::Set(char *key, int value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Integer::New(g_CurrentVM, value));
}

bool FunctionIMPL::Set(char *key, bool value) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	return obj->Set(v8::String::NewFromUtf8(g_CurrentVM, key), v8::Boolean::New(g_CurrentVM, value));
}

bool FunctionIMPL::Set(char *key, VoidFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::VoidCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, IntFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::IntCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, BoolFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::BoolCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, DoubleFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::DoubleCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, FloatFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::FloatCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, VoidPFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::VoidPointerCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, StringFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::StringCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

bool FunctionIMPL::Set(char *key, WideStringFunction cb) const
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::WideStringCallback, v8::External::New(g_CurrentVM, cb));
	v8::Local<v8::Function> func = wrapper->GetFunction();
	func->SetName(v8::String::NewFromUtf8(g_CurrentVM, key));

	return obj->Set(func->GetName(), func);
}

FunctionIMPL::FunctionIMPL(StringFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::StringCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

FunctionIMPL::FunctionIMPL(WideStringFunction cb)
{
	Isolate::Scope isolate_scope(g_CurrentVM);
	HandleScope handle_scope(g_CurrentVM);
	Local<Context> context = v8::Local<v8::Context>::New(g_CurrentVM, g_GlobalContext);
	Context::Scope context_scope(context);

	Local<v8::Object> obj = Handle<v8::Function>::New(g_CurrentVM, persisted_value);

	v8::Local<v8::FunctionTemplate> wrapper = v8::FunctionTemplate::New(g_CurrentVM, &CallbackInterfaces::WideStringCallback, v8::External::New(g_CurrentVM, cb));

	persisted_value.Reset(g_CurrentVM, wrapper->GetFunction());
}

void *FunctionIMPL::GetReference() const
{
	return NULL;
}