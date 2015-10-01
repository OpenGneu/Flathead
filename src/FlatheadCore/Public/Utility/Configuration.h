// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "API.h"

#pragma once

typedef void(*LoggingFunction)(int level, const char *message);

namespace Gneu
{
	namespace Utility
	{
		class FH_API Configuration
		{
		public:
			Configuration();
			Configuration(Configuration *);

			LoggingFunction LoggingFn();
			Configuration *LoggingFn(LoggingFunction);

			const char *Path();
			Configuration *Path(const char *);

			const char *Bootstrap();
			Configuration *Bootstrap(const char *);

			bool EnableHarmony();
			Configuration *EnableHarmony(bool);

			bool EnableHotReload();
			Configuration *EnableHotReload(bool);

			bool EnableESStaging();
			Configuration *EnableESStaging(bool);

			bool EnableHarmonyGenerators();
			Configuration *EnableHarmonyGenerators(bool); 

			bool EnableHarmonyDestructuring();
			Configuration *EnableHarmonyDestructuring(bool); 

			bool EnableHarmonyCollections();
			Configuration *EnableHarmonyCollections(bool);

			bool EnableHarmonyProxies();
			Configuration *EnableHarmonyProxies(bool);

			bool EnableHarmonyModules();
			Configuration *EnableHarmonyModules(bool);

			bool EnableHarmonyScoping();
			Configuration *EnableHarmonyScoping(bool);

			bool EnableHarmonyObservation();
			Configuration *EnableHarmonyObservation(bool);

			bool EnableHarmonySymbols();
			Configuration *EnableHarmonySymbols(bool);

			bool EnableHarmonyIteration();
			Configuration *EnableHarmonyIteration(bool);

			bool EnableHarmonyMaths();
			Configuration *EnableHarmonyMaths(bool);

			bool EnableHarmonyStrings();
			Configuration *EnableHarmonyStrings(bool);

			bool EnableHarmonyArrays();
			Configuration *EnableHarmonyArrays(bool);

			bool EnableHarmonyNumericLiterals();
			Configuration *EnableHarmonyNumericLiterals(bool); 

			bool EnableHarmonyTypeOf();
			Configuration *EnableHarmonyTypeOf(bool);

			bool ShouldInitializeImmediately();
			Configuration *ShouldInitializeImmediately(bool);

			bool AlwaysStrict();
			Configuration *AlwaysStrict(bool);

		protected:
			LoggingFunction loggingFunction;

			char path[2048];
			char bootstrap[2048];

			bool HotReload;

			bool ESStaging;

			bool Harmony;
			bool HarmonyGenerators;
			bool HarmonyCollections;
			bool HarmonyProxies;
			bool HarmonyModules;
			bool HarmonyScoping;
			bool HarmonyObservation;
			bool HarmonySymbols;
			bool HarmonyIteration;
			bool HarmonyMaths;
			bool HarmonyStrings;
			bool HarmonyArrays;
			bool HarmonyNumericLiterals;
			bool HarmonyTypeOf;
			bool HarmonyDestructuring;

			bool InitializeImmediately;
			bool Strict;
		};
	}
}