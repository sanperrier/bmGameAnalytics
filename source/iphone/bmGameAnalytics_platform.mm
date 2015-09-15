/*
 * iphone-specific implementation of the bmGameAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "bmGameAnalytics_internal.h"

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
    //TODO: Тут настраиваем валюты, типы предметов, устанавливаем версии и инициализируем ключами, проверок никаких не надо, они в generic части
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

void bmGameAnalyticsAddDesignEventWithValue_platform(const char * eventId, float* value)
{
	//TODO: тут надо в конце удалить value, т.к. он выделялся из кучи
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
