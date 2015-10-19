#pragma once

#include "Flathead.h"

namespace Gneu
{
	class RequiresFlathead
	{
	protected:
		static Flathead *pFH;

		static void SetupFlathead()
		{
			Configuration cfg;

			cfg.LoggingFn(TrackingLoggingFn);

			pFH = new Flathead(cfg);
		}

		static void CleanupFlathead()
		{
			delete pFH;
			pFH = NULL;
		}
	};
}