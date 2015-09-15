/*
 * iphone-specific implementation of the bmGameAnalytics extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#import <Foundation/Foundation.h>
#include "bmGameAnalytics_internal.h"
#include "GameAnalytics.h"
#include <string>
#include "s3eDebug.h"

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
#ifdef IW_DEBUG
    [GameAnalytics setEnabledInfoLog:YES];
    [GameAnalytics setEnabledVerboseLog:YES];
#else
    [GameAnalytics setEnabledInfoLog:NO];
    [GameAnalytics setEnabledVerboseLog:NO];
#endif
    
    if (build_version)
        [GameAnalytics configureBuild:[NSString stringWithUTF8String:build_version]];
    
    if (engine_version)
        [GameAnalytics configureEngineVersion:[NSString stringWithUTF8String:engine_version]];
    
    if (dimensions01)
    {
        NSMutableArray* dimensions = [[NSMutableArray alloc] init];
        for (int i = 0; i < dimensions01_size; i++) {
            [dimensions addObject:[NSString stringWithUTF8String:dimensions01[i]]];
        }
        NSArray *array = [dimensions copy];
        [GameAnalytics configureAvailableCustomDimensions01:array];
        [dimensions release];
    }
    
    if (dimensions02)
    {
        NSMutableArray* dimensions = [[NSMutableArray alloc] init];
        for (int i = 0; i < dimensions02_size; i++) {
            [dimensions addObject:[NSString stringWithUTF8String:dimensions02[i]]];
        }
        NSArray *array = [dimensions copy];
        [GameAnalytics configureAvailableCustomDimensions02:array];
        [dimensions release];
    }
    
    if (dimensions03)
    {
        NSMutableArray* dimensions = [[NSMutableArray alloc] init];
        for (int i = 0; i < dimensions03_size; i++) {
            [dimensions addObject:[NSString stringWithUTF8String:dimensions03[i]]];
        }
        NSArray *array = [dimensions copy];
        [GameAnalytics configureAvailableCustomDimensions03:array];
        [dimensions release];
    }
    
    if (resource_currencies)
    {
        NSMutableArray* currencies = [[NSMutableArray alloc] init];
        for (int i = 0; i < resource_currencies_size; i++) {
            [currencies addObject:[NSString stringWithUTF8String:resource_currencies[i]]];
        }
        NSArray *array = [currencies copy];
        [GameAnalytics configureAvailableResourceCurrencies:array];
        [currencies release];
    }
    
    if (resource_item_types)
    {
        NSMutableArray* types = [[NSMutableArray alloc] init];
        for (int i = 0; i < resource_item_types_size; i++) {
            [types addObject:[NSString stringWithUTF8String:resource_item_types[i]]];
        }
        NSArray *array = [types copy];
        [GameAnalytics configureAvailableResourceItemTypes:array];
        [types release];
    }
    
    NSString* gamek = [NSString stringWithUTF8String:game_key];
    NSString* secretk = [NSString stringWithUTF8String:secret_key];
    [GameAnalytics initializeWithGameKey:gamek
                              gameSecret:secretk];
    return S3E_RESULT_SUCCESS;
}

void bmGameAnalyticsTerminate_platform()
{
    
}

void bmGameAnalyticsAddBusinessEvent_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt)
{
    NSString* curr = [NSString stringWithUTF8String:currency];
    NSString* type = [NSString stringWithUTF8String:itemType];
    NSString* item = [NSString stringWithUTF8String:itemId];
    NSString* cart = [NSString stringWithUTF8String:cartType];
    
    if (receipt)
    {
        NSString* rec = [NSString stringWithUTF8String:receipt];
        [GameAnalytics addBusinessEventWithCurrency:curr
                                             amount:amount
                                           itemType:type
                                             itemId:item
                                           cartType:cart
                                            receipt:rec];
    }
    else
    {
        [GameAnalytics addBusinessEventWithCurrency:curr
                                             amount:amount
                                           itemType:type
                                             itemId:item
                                           cartType:cart
                                   autoFetchReceipt:true];
    }
}

void bmGameAnalyticsAddBusinessEventWithoutReceipt_platform(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType)
{
    NSString* curr = [NSString stringWithUTF8String:currency];
    NSString* type = [NSString stringWithUTF8String:itemType];
    NSString* item = [NSString stringWithUTF8String:itemId];
    NSString* cart = [NSString stringWithUTF8String:cartType];
    
    [GameAnalytics addBusinessEventWithCurrency:curr
                                         amount:amount
                                       itemType:type
                                         itemId:item
                                       cartType:cart
                               autoFetchReceipt:false];
}

void bmGameAnalyticsAddResourceEvent_platform(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId)
{
    NSString* curr = [NSString stringWithUTF8String:currency];
    NSString* type = [NSString stringWithUTF8String:itemType];
    NSString* item = [NSString stringWithUTF8String:itemId];
    [GameAnalytics addResourceEventWithFlowType:GAResourceFlowTypeSource
                                       currency:curr
                                         amount:[NSNumber numberWithInteger:amount]
                                       itemType:type
                                         itemId:item];
}

void bmGameAnalyticsAddProgressionEventWithScore_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score)
{
    NSString* progress01 = [NSString stringWithUTF8String:progression01];
    NSString* progress02 = [NSString stringWithUTF8String:progression02];
    NSString* progress03 = [NSString stringWithUTF8String:progression03];
    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus
                                              progression01:progress01
                                              progression02:progress02
                                              progression03:progress03
                                                      score:score];
}

void bmGameAnalyticsAddProgressionEvent_platform(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03)
{
    NSString* progress01 = [NSString stringWithUTF8String:progression01];
    NSString* progress02 = [NSString stringWithUTF8String:progression02];
    NSString* progress03 = [NSString stringWithUTF8String:progression03];
    [GameAnalytics addProgressionEventWithProgressionStatus:(GAProgressionStatus)progressionStatus
                                              progression01:progress01
                                              progression02:progress02
                                              progression03:progress03];
}

void bmGameAnalyticsAddDesignEvent_platform(const char * eventId)
{
    NSString* event = [NSString stringWithUTF8String:eventId];
    [GameAnalytics addDesignEventWithEventId:event];
}

void bmGameAnalyticsAddDesignEventWithValue_platform(const char * eventId, float* value)
{
    if (value)
    {
        NSString* event = [NSString stringWithUTF8String:eventId];
        [GameAnalytics addDesignEventWithEventId:event
                                           value:[NSNumber numberWithFloat:*value]];
        delete value;
    }
}

void bmGameAnalyticsAddErrorEvent_platform(bmGameAnalyticsErrorSeverity severity, const char * message)
{
    if (message)
    {
        NSString* msg = [NSString stringWithUTF8String:message];
        [GameAnalytics addErrorEventWithSeverity:(GAErrorSeverity)severity
                                         message:msg];
    }
    else
    {
        [GameAnalytics addErrorEventWithSeverity:(GAErrorSeverity)severity
                                         message:nil];
    }
}

void bmGameAnalyticsSetCustomDimension01_platform(const char * dimension01)
{
    NSString* dim01 = [NSString stringWithUTF8String:dimension01];
    [GameAnalytics setCustomDimension01:dim01];
}

void bmGameAnalyticsSetCustomDimension02_platform(const char * dimension02)
{
    NSString* dim02 = [NSString stringWithUTF8String:dimension02];
    [GameAnalytics setCustomDimension02:dim02];
}

void bmGameAnalyticsSetCustomDimension03_platform(const char * dimension03)
{
    NSString* dim03 = [NSString stringWithUTF8String:dimension03];
    [GameAnalytics setCustomDimension03:dim03];
}

void bmGameAnalyticsSetUserFacebookId_platform(const char * facebookId)
{
    NSString* fb_id = [NSString stringWithUTF8String:facebookId];
    [GameAnalytics setFacebookId:fb_id];
}

void bmGameAnalyticsSetUserGender_platform(bool is_male)
{
    [GameAnalytics setGender:is_male ? @"male" : @"female"];
}

void bmGameAnalyticsSetUserBirthYear_platform(int year)
{
    [GameAnalytics setBirthYear:year];
}
