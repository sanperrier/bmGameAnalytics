#include "s3e.h"
#include "bmGameAnalytics.h"
#include <string>

int main()
{
	if (bmGameAnalyticsAvailable())
	{

	}

    while (!s3eDeviceCheckQuitRequest())
    {
        // Fill background blue
        s3eSurfaceClear(0, 0, 255);

        // Flip the surface buffer to screen
        s3eSurfaceShow();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

    return 0;
}
