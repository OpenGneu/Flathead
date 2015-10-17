// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#include "Utility/Configuration.h"
#include "Types/Value.h"

#pragma once

namespace Gneu
{
	using namespace Utility;

	class FH_API Flathead
	{
	public:
		Flathead();
		~Flathead();
		Flathead(Configuration &);

		Configuration *GetConfiguration(); 

		void InitializeV8();

		void InitializeGlobalContext();
		void PreloadCore();

		void CleanupV8();
		void Tick(float delta);

		Types::Value *Get(char *);
		bool Set(char *, char *);
		bool Set(char *, double);
		bool Set(char *, int);
		bool Set(char *, bool);

		void Execute(char *input, char *output);

		void Execute(char *input, bool &output);

		void Execute(char *input, double &output);
		void Execute(char *input, float &output);
		void Execute(char *input, int &output);
		void Execute(char *input, long long &output);

	protected:
		void HandleV8Flags();

		void JSTick(float delta);

	private:
		Configuration *configuration;
	};
}
