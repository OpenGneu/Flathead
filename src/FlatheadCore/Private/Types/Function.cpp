#include "stdafx.h"
#include "Types/Function.h"
#include "Private/Types/impl/FunctionIMPL.h"

using namespace Gneu::Types;

Gneu::Types::Function *Gneu::Types::Function::New(VoidFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(IntFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(BoolFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(FloatFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(DoubleFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(VoidPFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(StringFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}

Gneu::Types::Function *Gneu::Types::Function::New(WideStringFunction pFN)
{
	return new Gneu::Types::FunctionIMPL(pFN);
}
