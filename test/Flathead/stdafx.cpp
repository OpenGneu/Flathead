// stdafx.cpp : source file that includes just the standard includes
// Flathead.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int g_Type = -1;
char g_Buffer[2048];

void TrackingLoggingFn(int type, const char *msg)
{
	g_Type = type;
	strncpy_s(g_Buffer, strlen(msg) + 1, msg, _TRUNCATE);
	Logger::WriteMessage(g_Buffer);
	Logger::WriteMessage("\n");
}

void ResetTracking()
{
	g_Type = -1;
	strncpy_s(g_Buffer, "", _TRUNCATE);
}