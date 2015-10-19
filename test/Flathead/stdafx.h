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
void WriteToFile(char *fileName, char *output);
void ResetTracking();

#pragma comment(lib, "WINMM.LIB")
#pragma comment(lib, "icuuc.lib")
#pragma comment(lib, "icui18n.lib")
#pragma comment(lib, "v8.lib")
#pragma comment(lib, "v8_libbase.lib")
#pragma comment(lib, "v8_libplatform.lib")