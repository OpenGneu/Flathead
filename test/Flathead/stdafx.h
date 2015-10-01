// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// Headers for CppUnitTest
#include "CppUnitTest.h"

// TODO: reference additional headers your program requires here

extern int g_Type;
extern char g_Buffer[];

void TrackingLoggingFn(int type, const char *msg);
void ResetTracking();