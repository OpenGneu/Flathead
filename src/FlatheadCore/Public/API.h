// Copyright 2014 Gneu LLC. All Rights Reserved.

#pragma once

#ifdef FLATHEADCORE_EXPORTS
#define FH_API	__declspec(dllexport)
#else
#define FH_API  __declspec(dllimport)
#endif
