// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"

#include <stdio.h>  /* defines FILENAME_MAX */
#include <stdlib.h>  
#include <direct.h>

#include <chrono>
#include <thread>

#include "Flathead.h"
#include "Utility/Configuration.h"

using namespace Gneu;
using namespace Gneu::Utility;

#define GetCurrentDir _getcwd

void WriteToFile(char *fileName, char *output);

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Attempting to setup binding...\n");

	Configuration cfg;

	cfg.EnableHarmonyDestructuring(true);

	Flathead *pFH = new Flathead(cfg);
	char buffer[4096];
	WriteToFile("lib/HotReload.js", "");

	pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);

	std::this_thread::sleep_for(std::chrono::seconds(1)); // Only limitation is the resolution reported by filesystem =\

	WriteToFile("lib/HotReload.js", "exports.value = {test: 42};");

	pFH->Tick(1.0f);

	pFH->Execute("JSON.stringify(require('./HotReload'));", buffer);
	
	delete pFH;
	pFH = NULL;

	return 0;
}

void WriteToFile(char *fileName, char *output)
{
	FILE* file;

	if (fopen_s(&file, fileName, "w"))
	{
		return;
	}

	fprintf(file, output);

	fclose(file);
}