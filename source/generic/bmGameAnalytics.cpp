/*
Generic implementation of the bmGameAnalytics extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
 
#include <vector>
#include <algorithm>
#include "IwDebug.h"
#include "s3eConfig.h"
#include "MarmaladeVersion.h"

#include "bmGameAnalytics_internal.h"


using namespace std;

namespace
{
	char* s_game_key;
	char* s_secret_key;
	char* s_build_version;
	char* s_engine_version;
	vector<const char*> s_dimensions01;
	vector<const char*> s_dimensions02;
	vector<const char*> s_dimensions03;
	vector<const char*> s_resource_currencies;
	vector<const char*> s_resource_item_types;
};

s3eResult bmGameAnalyticsInit()
{
	char* s_game_key = new char[0xff];
	char* s_secret_key = new char[0xff];
	char* s_build_version = new char[0xff];
	char* s_engine_version = new char[0xff];

	IwTrace(BMGAMEANALYTICS_VERBOSE, ("reading config"));

	if (s3eConfigGetString("bmGameAnalytics", "GameKey", s_game_key) == S3E_RESULT_ERROR)
	{
		S3E_EXT_ERROR(CONFIG, ("GameKey is incorrect or not set in app.icf"));
		return S3E_RESULT_ERROR;
	}

	if (s3eConfigGetString("bmGameAnalytics", "SecretKey", s_secret_key) == S3E_RESULT_ERROR)
	{
		S3E_EXT_ERROR(CONFIG, ("SecretKey is incorrect or not set in app.icf"));
		return S3E_RESULT_ERROR;
	}

	if (s3eConfigGetString("bmGameAnalytics", "BuildVersion", s_build_version) == S3E_RESULT_ERROR)
	{
		s_build_version[0] = NULL;
		s3eConfigGetString("S3E", "SysAppVersion", s_build_version);
	}

	if (s3eConfigGetString("bmGameAnalytics", "EngineVersion", s_engine_version) == S3E_RESULT_ERROR)
	{
		s_engine_version = MARMALADE_VERSION_STRING_FULL;
	}

	string dimensions;
	char buffer[0xff] = { NULL };
	if (s3eConfigGetString("bmGameAnalytics", "CustomDimensions01", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { NULL };
		char buffer2[0xff] = { NULL };
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions01_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions01_part3", buffer2);
		
		dimensions = string(buffer) + string(buffer1) + string(buffer2);
	}
	
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("config loaded"));

    //Add any generic initialisation code here
	return bmGameAnalyticsInit_platform(s_game_key, 
		s_secret_key, 
		s_build_version, 
		s_engine_version, 
		s_dimensions01.empty() ? nullptr : &s_dimensions01.front(), s_dimensions01.size(),
		s_dimensions02.empty() ? nullptr : &s_dimensions02.front(), s_dimensions02.size(),
		s_dimensions03.empty() ? nullptr : &s_dimensions03.front(), s_dimensions03.size(),
		s_resource_currencies.empty() ? nullptr : &s_resource_currencies.front(), s_resource_currencies.size(),
		s_resource_item_types.empty() ? nullptr : &s_resource_item_types.front(), s_resource_item_types.size());
}

void bmGameAnalyticsTerminate()
{
    //Add any generic termination code here
    bmGameAnalyticsTerminate_platform();
}

void bmGameAnalyticsAddBusinessEvent(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt)
{
	bmGameAnalyticsAddBusinessEvent_platform(currency, amount, itemType, itemId, cartType, receipt);
}

void bmGameAnalyticsAddResourceEvent(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId)
{
	if (find_if(s_resource_currencies.begin(), s_resource_currencies.end(), [&](const char* item) { return strcmp(item, currency) == 0; }) == s_resource_currencies.end())
	{
		S3E_EXT_ERROR(PARAM, ("Incorrect resource currency: %s", currency));
		return;
	}

	if (find_if(s_resource_item_types.begin(), s_resource_item_types.end(), [&](const char* item) { return strcmp(item, itemType) == 0; }) == s_resource_item_types.end())
	{
		S3E_EXT_ERROR(PARAM, ("Incorrect resource item type: %s", itemType));
		return;
	} 

	bmGameAnalyticsAddResourceEvent_platform(flowType, currency, amount, itemType, itemId);
}

void bmGameAnalyticsAddProgressionEventWithScore(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score)
{
	bmGameAnalyticsAddProgressionEventWithScore_platform(progressionStatus, progression01, progression02, progression03, score);
}

void bmGameAnalyticsAddProgressionEvent(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03)
{
	bmGameAnalyticsAddProgressionEvent_platform(progressionStatus, progression01, progression02, progression03);
}

void bmGameAnalyticsAddDesignEvent(const char * eventId)
{
	bmGameAnalyticsAddDesignEvent_platform(eventId);
}

void bmGameAnalyticsAddDesignEventWithValue(const char * eventId, float value)
{
	float* _value = new float(value);
	IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddDesignEvent"));
	s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddDesignEventWithValue_platform, 2, eventId, _value);
}

void bmGameAnalyticsAddErrorEvent(bmGameAnalyticsErrorSeverity severity, const char * message)
{
	bmGameAnalyticsAddErrorEvent_platform(severity, message);
}

void bmGameAnalyticsSetCustomDimension01(const char * dimension01)
{
	bmGameAnalyticsSetCustomDimension01_platform(dimension01);
}

void bmGameAnalyticsSetCustomDimension02(const char * dimension02)
{
	bmGameAnalyticsSetCustomDimension02_platform(dimension02);
}

void bmGameAnalyticsSetCustomDimension03(const char * dimension03)
{
	bmGameAnalyticsSetCustomDimension03_platform(dimension03);
}

void bmGameAnalyticsSetUserFacebookId(const char * facebookId)
{
	bmGameAnalyticsSetUserFacebookId_platform(facebookId);
}

void bmGameAnalyticsSetUserGender(bool is_male)
{
	bmGameAnalyticsSetUserGender_platform(is_male);
}

void bmGameAnalyticsSetUserBirthYear(int year)
{
	bmGameAnalyticsSetUserBirthYear_platform(year);
}
