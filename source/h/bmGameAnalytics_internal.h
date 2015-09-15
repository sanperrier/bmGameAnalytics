/*
 * Internal header for the bmGameAnalytics extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef BMGAMEANALYTICS_INTERNAL_H
#define BMGAMEANALYTICS_INTERNAL_H

#include "s3eTypes.h"
#include "bmGameAnalytics.h"
#include "bmGameAnalytics_autodefs.h"

#define S3E_CURRENT_EXT BMGAMEANALYTICS
#include "s3eEdkError.h"

/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult bmGameAnalyticsInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult bmGameAnalyticsInit_platform(const char * game_key, 
                                       const char * secret_key, 
                                       const char * build_version, 
                                       const char * engine_version,
									   const char ** dimensions01, unsigned int dimensions01_size,
									   const char ** dimensions02, unsigned int dimensions02_size,
									   const char ** dimensions03, unsigned int dimensions03_size,
									   const char ** resource_currencies, unsigned int resource_currencies_size,
									   const char ** resource_item_types, unsigned int resource_item_types_size);

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void bmGameAnalyticsTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void bmGameAnalyticsTerminate_platform();
void bmGameAnalyticsAddBusinessEvent_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt);

void bmGameAnalyticsAddResourceEvent_platform(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId);

void bmGameAnalyticsAddProgressionEventWithScore_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score);

void bmGameAnalyticsAddProgressionEvent_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03);

void bmGameAnalyticsAddDesignEvent_platform(const char * eventId);

void bmGameAnalyticsAddDesignEventWithValue_platform(const char * eventId, int value);

void bmGameAnalyticsAddErrorEvent_platform(bmGameAnalyticsErrorSeverity severity, const char * message);

void bmGameAnalyticsSetCustomDimension01_platform(const char * dimension01);

void bmGameAnalyticsSetCustomDimension02_platform(const char * dimension02);

void bmGameAnalyticsSetCustomDimension03_platform(const char * dimension03);

void bmGameAnalyticsSetUserFacebookId_platform(const char * facebookId);

void bmGameAnalyticsSetUserGender_platform(bool is_male);

void bmGameAnalyticsSetUserBirthYear_platform(int year);


#endif /* !BMGAMEANALYTICS_INTERNAL_H */