// Copyright 2015 Gneu LLC. All Rights Reserved.

#include "stdafx.h"

#include <stdio.h>  /* defines FILENAME_MAX */
#include <stdlib.h>  
#include <direct.h>

#include "Flathead.h"
#include "Utility/Configuration.h"

using namespace Gneu;
using namespace Gneu::Utility;

#define GetCurrentDir _getcwd

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Attempting to setup binding...\n");

	Configuration cfg;

	cfg.EnableHarmonyDestructuring(true);

	Flathead *pFH = new Flathead(cfg);
	char buffer[4096];

	pFH->Execute("var meaning = require('./sampleJSON.json'); meaning.meaningOfLife;", buffer);
	pFH->Execute("var meaning = require('./sampleModule'); meaning.meaningOfLife;", buffer);
	
	delete pFH;
	pFH = NULL;

	return 0;
}