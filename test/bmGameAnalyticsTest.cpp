#include "s3e.h"
#include "bmGameAnalytics.h"
#include <string>

int main()
{
	if (bmGameAnalyticsAvailable())
	{
        bmGameAnalyticsSetUserGender(true);
        bmGameAnalyticsSetUserFacebookId("123");
        bmGameAnalyticsSetUserBirthYear(1999);
        
        bmGameAnalyticsSetCustomDimension01("dim11");
        bmGameAnalyticsAddBusinessEvent("bite", 10, "skin", "1", "shop");
        
        bmGameAnalyticsSetCustomDimension02("dim21");
        bmGameAnalyticsAddDesignEventWithValue("level_complete", 1);
        
        bmGameAnalyticsSetCustomDimension03("dim31");
        bmGameAnalyticsAddDesignEvent("start");
        
        bmGameAnalyticsAddErrorEvent(bmGameAnalyticsErrorSeverityCritical, "Error!!!");
        bmGameAnalyticsAddProgressionEvent(bmGameAnalyticsProgressionStatusComplete, "1", "2", "3");
        bmGameAnalyticsAddProgressionEventWithScore(bmGameAnalyticsProgressionStatusComplete, "1", "2", "3", 125);
        bmGameAnalyticsAddResourceEvent(bmGameAnalyticsResourceFlowTypeSource, "currencyTwo", 10, "typeTwo", "1488");
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
