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
#include <sstream>

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

	void clean()
	{
		for (const char* item : s_dimensions01)
			delete item;

		for (const char* item : s_dimensions02)
			delete item;

		for (const char* item : s_dimensions03)
			delete item;

		for (const char* item : s_resource_currencies)
			delete item;

		for (const char* item : s_resource_item_types)
			delete item;
	}
};

s3eResult bmGameAnalyticsInit()
{
	//TODO: разобраться, почему не работает вывод ошибок
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

	char buffer[0xff] = { '\0' };
	if (s3eConfigGetString("bmGameAnalytics", "CustomDimensions01", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { '\0' };
		char buffer2[0xff] = { '\0' };
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions01_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions01_part3", buffer2);
		
		string dimensions = string(buffer) + ',' + string(buffer1) + ',' + string(buffer2);

		stringstream ss(dimensions);
		string item;
		while (getline(ss, item, ','))
		{
			if (!item.empty())
			{
				if (s_dimensions01.size() >= 20)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("Too many items for CustomDimensions01"));
					return S3E_RESULT_ERROR;
				}

				if (item.size() > 32)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("One of item of CustomDimensions01 is too long (max length 32 chars): %s", item.c_str()));
					return S3E_RESULT_ERROR;
				}

				char* dimension = new char[item.size() + 1];
				std::copy(item.begin(), item.end(), dimension);
				dimension[item.size()] = '\0';
				s_dimensions01.push_back(dimension);
			}
		}
	}

	fill_n(buffer, 0xff, '\0');
	if (s3eConfigGetString("bmGameAnalytics", "CustomDimensions02", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { '\0' };
		char buffer2[0xff] = { '\0' };
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions02_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions02_part3", buffer2);

		string dimensions = string(buffer) + ',' + string(buffer1) + ',' + string(buffer2);

		stringstream ss(dimensions);
		string item;
		while (getline(ss, item, ','))
		{
			if (!item.empty())
			{
				if (s_dimensions02.size() >= 20)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("Too many items for CustomDimensions02"));
					return S3E_RESULT_ERROR;
				}

				if (item.size() > 32)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("One of item of CustomDimensions02 is too long (max length 32 chars): %s", item.c_str()));
					return S3E_RESULT_ERROR;
				}

				char* dimension = new char[item.size() + 1];
				std::copy(item.begin(), item.end(), dimension);
				dimension[item.size()] = '\0';
				s_dimensions02.push_back(dimension);
			}
		}
	}
	
	fill_n(buffer, 0xff, '\0');
	if (s3eConfigGetString("bmGameAnalytics", "CustomDimensions03", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { '\0' };
		char buffer2[0xff] = { '\0' };
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions03_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "CustomDimensions03_part3", buffer2);

		string dimensions = string(buffer) + ',' + string(buffer1) + ',' + string(buffer2);

		stringstream ss(dimensions);
		string item;
		while (getline(ss, item, ','))
		{
			if (!item.empty())
			{
				if (s_dimensions03.size() >= 20)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("Too many items for CustomDimensions03"));
					return S3E_RESULT_ERROR;
				}

				if (item.size() > 32)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("One of item of CustomDimensions03 is too long (max length 32 chars): %s", item.c_str()));
					return S3E_RESULT_ERROR;
				}

				char* dimension = new char[item.size() + 1];
				std::copy(item.begin(), item.end(), dimension);
				dimension[item.size()] = '\0';
				s_dimensions03.push_back(dimension);
			}
		}
	}


	fill_n(buffer, 0xff, '\0');
	if (s3eConfigGetString("bmGameAnalytics", "ResourceCurrencies", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { '\0' };
		char buffer2[0xff] = { '\0' };
		s3eConfigGetString("bmGameAnalytics", "ResourceCurrencies_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "ResourceCurrencies_part3", buffer2);

		string currencies = string(buffer) + ',' + string(buffer1) + ',' + string(buffer2);

		stringstream ss(currencies);
		string item;
		while (getline(ss, item, ','))
		{
			if (!item.empty())
			{
				if (s_resource_currencies.size() >= 20)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("Too many items for ResourceCurrencies"));
					return S3E_RESULT_ERROR;
				}

				if (item.size() > 32)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("One of item of ResourceCurrencies is too long (max length 32 chars): %s", item.c_str()));
					return S3E_RESULT_ERROR;
				}

				char* dimension = new char[item.size() + 1];
				std::copy(item.begin(), item.end(), dimension);
				dimension[item.size()] = '\0';
				s_resource_currencies.push_back(dimension);
			}
		}
	}

	fill_n(buffer, 0xff, '\0');
	if (s3eConfigGetString("bmGameAnalytics", "ResourceItemTypes", buffer) == S3E_RESULT_SUCCESS)
	{
		char buffer1[0xff] = { '\0' };
		char buffer2[0xff] = { '\0' };
		s3eConfigGetString("bmGameAnalytics", "ResourceItemTypes_part2", buffer1);
		s3eConfigGetString("bmGameAnalytics", "ResourceItemTypes_part3", buffer2);

		string types = string(buffer) + ',' + string(buffer1) + ',' + string(buffer2);

		stringstream ss(types);
		string item;
		while (getline(ss, item, ','))
		{
			if (!item.empty())
			{
				if (s_resource_item_types.size() >= 20)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("Too many items for ResourceItemTypes"));
					return S3E_RESULT_ERROR;
				}

				if (item.size() > 32)
				{
					clean();
					S3E_EXT_ERROR(CONFIG, ("One of item of ResourceItemTypes is too long (max length 32 chars): %s", item.c_str()));
					return S3E_RESULT_ERROR;
				}

				char* dimension = new char[item.size() + 1];
				std::copy(item.begin(), item.end(), dimension);
				dimension[item.size()] = '\0';
				s_resource_item_types.push_back(dimension);
			}
		}
	}

	IwTrace(BMGAMEANALYTICS_VERBOSE, ("config loaded"));

	for (const char* item : s_dimensions01) {
		IwTrace(BMGAMEANALYTICS_VERBOSE, ("%s", item));
	}

	for (const char* item : s_dimensions02){
		IwTrace(BMGAMEANALYTICS_VERBOSE, ("%s", item));
	}

	for (const char* item : s_dimensions03){
		IwTrace(BMGAMEANALYTICS_VERBOSE, ("%s", item));
	}

	for (const char* item : s_resource_currencies){
		IwTrace(BMGAMEANALYTICS_VERBOSE, ("%s", item));
	}

	for (const char* item : s_resource_item_types){
		IwTrace(BMGAMEANALYTICS_VERBOSE, ("%s", item));
	}

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
	clean();

    bmGameAnalyticsTerminate_platform();
}

void bmGameAnalyticsAddBusinessEventWithoutReceipt(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType)
{
	bmGameAnalyticsAddBusinessEventWithoutReceipt_platform(currency, amount, itemType, itemId, cartType);
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
