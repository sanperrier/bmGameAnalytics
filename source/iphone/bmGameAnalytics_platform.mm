/*
 * iphone-specific implementation of the bmGameAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "bmGameAnalytics_internal.h"

s3eResult bmGameAnalyticsInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void bmGameAnalyticsTerminate_platform()
{ 
}

void bmGameAnalyticsAddBusinessEvent_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt)
{
}

void bmGameAnalyticsAddResourceEvent_platform(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId)
{
}

void bmGameAnalyticsAddProgressionEventWithScore_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score)
{
}

void bmGameAnalyticsAddProgressionEvent_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03)
{
}

void bmGameAnalyticsAddDesignEvent_platform(const char * eventId)
{
}

void bmGameAnalyticsAddDesignEventWithValue_platform(const char * eventId, int value)
{
}

void bmGameAnalyticsAddErrorEvent_platform(bmGameAnalyticsErrorSeverity severity, const char * message)
{
}

void bmGameAnalyticsSetCustomDimension01_platform(const char * dimension01)
{
}

void bmGameAnalyticsSetCustomDimension02_platform(const char * dimension02)
{
}

void bmGameAnalyticsSetCustomDimension03_platform(const char * dimension03)
{
}

void bmGameAnalyticsSetUserFacebookId_platform(const char * facebookId)
{
}

void bmGameAnalyticsSetUserGender_platform(bool is_male)
{
}

void bmGameAnalyticsSetUserBirthYear_platform(int year)
{
}
