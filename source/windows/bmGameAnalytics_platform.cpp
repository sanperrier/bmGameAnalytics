/*
 * windows-specific implementation of the bmGameAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "bmGameAnalytics_internal.h"

#include "IwDebug.h"

s3eResult bmGameAnalyticsInit_platform(const char * game_key,
	const char * secret_key,
	const char * build_version,
	const char * engine_version,
	const char ** dimensions01, unsigned int dimensions01_size,
	const char ** dimensions02, unsigned int dimensions02_size,
	const char ** dimensions03, unsigned int dimensions03_size,
	const char ** resource_currencies, unsigned int resource_currencies_size,
	const char ** resource_item_types, unsigned int resource_item_types_size)
{
    // Add any platform-specific initialisation code here

	IwTrace(BMGAMEANALYTICS_VERBOSE, (
		"[bmGameAnalyticsInit_platform]" 
		"GameKey: %s, SecretKey: %s, Build version: %s, Engine version: %s,"
		"Custom dimensions 01 size: %u, Custom dimensions 02 size: %u, Custom dimensions 03 size: %u,"
		"Resource currencies size: %u,"
		"Resource item types: %u",
		game_key, secret_key, build_version, engine_version,
		dimensions01_size, dimensions02_size, dimensions03_size,
		resource_currencies_size,
		resource_item_types_size));

    return S3E_RESULT_SUCCESS;
}

void bmGameAnalyticsTerminate_platform()
{ 
}

void bmGameAnalyticsAddBusinessEventWithoutReceipt_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddBusinessEventWithoutReceipt_platform] Currency: %s, Amount: %d, ItemType: %s, ItemId: %s, CartType: %s",
		currency, amount, itemType, itemId, cartType));
}

void bmGameAnalyticsAddBusinessEvent_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddBusinessEvent_platform] Currency: %s, Amount: %d, ItemType: %s, ItemId: %s, CartType: %s, Receipt: %s",
		currency, amount, itemType, itemId, cartType, receipt));
}

void bmGameAnalyticsAddResourceEvent_platform(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddResourceEvent_platform] FlowType: %s, Currency: %s, Amount: %d, ItemType: %s, ItemId: %s",
		flowType == bmGameAnalyticsResourceFlowTypeSource ? "source" : "sink", currency, amount, itemType, itemId));
}

void bmGameAnalyticsAddProgressionEventWithScore_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score)
{
	const char* status;
	switch (progressionStatus)
	{
	case bmGameAnalyticsProgressionStatusStart:
		status = "start";
		break;
	case bmGameAnalyticsProgressionStatusFail:
		status = "fail";
		break;
	case bmGameAnalyticsProgressionStatusComplete:
		status = "complete";
		break;
	}
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddProgressionEventWithScore_platform] ProgressionStatus: %s, Progression01: %s, Progression02: %s, Progression03: %s, Score: %d",
		status, progression01, progression02, progression03, score));
}

void bmGameAnalyticsAddProgressionEvent_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03)
{
	const char* status;
	switch (progressionStatus)
	{
	case bmGameAnalyticsProgressionStatusStart:
		status = "start";
		break;
	case bmGameAnalyticsProgressionStatusFail:
		status = "fail";
		break;
	case bmGameAnalyticsProgressionStatusComplete:
		status = "complete";
		break;
	}
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddProgressionEvent_platform] ProgressionStatus: %s, Progression01: %s, Progression02: %s, Progression03: %s",
		status, progression01, progression02, progression03));
}

void bmGameAnalyticsAddDesignEvent_platform(const char * eventId)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddDesignEvent_platform] EventId: %s",
		eventId));
}

void bmGameAnalyticsAddDesignEventWithValue_platform(const char * eventId, float * value)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddDesignEventWithValue_platform] EventId: %s, Value: %f",
		eventId, *value));

	delete value;
}

void bmGameAnalyticsAddErrorEvent_platform(bmGameAnalyticsErrorSeverity severity, const char * message)
{
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("[bmGameAnalyticsAddErrorEvent_platform] Severity: %d, Message: %s",
		severity, message));
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
