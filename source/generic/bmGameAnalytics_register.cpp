/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "bmGameAnalytics_autodefs.h"
#include "s3eEdk.h"
#include "bmGameAnalytics.h"
//Declarations of Init and Term functions
extern s3eResult bmGameAnalyticsInit();
extern void bmGameAnalyticsTerminate();


const char* bmGameAnalyticsGetErrorString()
{
#ifdef S3E_STORE_ERROR_STRINGS
    return s3eEdkErrorGetString(S3E_EXT_BMGAMEANALYTICS_HASH);
#else
    return NULL;
#endif
}

bmGameAnalyticsError bmGameAnalyticsGetError()
{
    return (bmGameAnalyticsError) s3eEdkErrorGet(S3E_EXT_BMGAMEANALYTICS_HASH);
}

// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void bmGameAnalyticsAddBusinessEventWithoutReceipt_wrap(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddBusinessEventWithoutReceipt"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddBusinessEventWithoutReceipt, 5, currency, amount, itemType, itemId, cartType);
}

static void bmGameAnalyticsAddBusinessEvent_wrap(const char * currency, int amount, const char * itemType, const char * itemId, const char * cartType, const char * receipt)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddBusinessEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddBusinessEvent, 6, currency, amount, itemType, itemId, cartType, receipt);
}

static void bmGameAnalyticsAddResourceEvent_wrap(bmGameAnalyticsResourceFlowType flowType, const char * currency, int amount, const char * itemType, const char * itemId)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddResourceEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddResourceEvent, 5, flowType, currency, amount, itemType, itemId);
}

static void bmGameAnalyticsAddProgressionEventWithScore_wrap(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03, int score)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddProgressionEventWithScore"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddProgressionEventWithScore, 5, progressionStatus, progression01, progression02, progression03, score);
}

static void bmGameAnalyticsAddProgressionEvent_wrap(bmGameAnalyticsProgressionStatus progressionStatus, const char * progression01, const char * progression02, const char * progression03)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddProgressionEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddProgressionEvent, 4, progressionStatus, progression01, progression02, progression03);
}

static void bmGameAnalyticsAddDesignEvent_wrap(const char * eventId)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddDesignEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddDesignEvent, 1, eventId);
}

static void bmGameAnalyticsAddErrorEvent_wrap(bmGameAnalyticsErrorSeverity severity, const char * message)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsAddErrorEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsAddErrorEvent, 2, severity, message);
}

static void bmGameAnalyticsSetCustomDimension01_wrap(const char * dimension01)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetCustomDimension01"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetCustomDimension01, 1, dimension01);
}

static void bmGameAnalyticsSetCustomDimension02_wrap(const char * dimension02)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetCustomDimension02"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetCustomDimension02, 1, dimension02);
}

static void bmGameAnalyticsSetCustomDimension03_wrap(const char * dimension03)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetCustomDimension03"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetCustomDimension03, 1, dimension03);
}

static void bmGameAnalyticsSetUserFacebookId_wrap(const char * facebookId)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetUserFacebookId"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetUserFacebookId, 1, facebookId);
}

static void bmGameAnalyticsSetUserGender_wrap(bool is_male)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetUserGender"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetUserGender, 1, is_male);
}

static void bmGameAnalyticsSetUserBirthYear_wrap(int year)
{
    IwTrace(BMGAMEANALYTICS_VERBOSE, ("calling bmGameAnalytics func on main thread: bmGameAnalyticsSetUserBirthYear"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)bmGameAnalyticsSetUserBirthYear, 1, year);
}

#define bmGameAnalyticsAddBusinessEventWithoutReceipt bmGameAnalyticsAddBusinessEventWithoutReceipt_wrap
#define bmGameAnalyticsAddBusinessEvent bmGameAnalyticsAddBusinessEvent_wrap
#define bmGameAnalyticsAddResourceEvent bmGameAnalyticsAddResourceEvent_wrap
#define bmGameAnalyticsAddProgressionEventWithScore bmGameAnalyticsAddProgressionEventWithScore_wrap
#define bmGameAnalyticsAddProgressionEvent bmGameAnalyticsAddProgressionEvent_wrap
#define bmGameAnalyticsAddDesignEvent bmGameAnalyticsAddDesignEvent_wrap
#define bmGameAnalyticsAddErrorEvent bmGameAnalyticsAddErrorEvent_wrap
#define bmGameAnalyticsSetCustomDimension01 bmGameAnalyticsSetCustomDimension01_wrap
#define bmGameAnalyticsSetCustomDimension02 bmGameAnalyticsSetCustomDimension02_wrap
#define bmGameAnalyticsSetCustomDimension03 bmGameAnalyticsSetCustomDimension03_wrap
#define bmGameAnalyticsSetUserFacebookId bmGameAnalyticsSetUserFacebookId_wrap
#define bmGameAnalyticsSetUserGender bmGameAnalyticsSetUserGender_wrap
#define bmGameAnalyticsSetUserBirthYear bmGameAnalyticsSetUserBirthYear_wrap

#endif

void bmGameAnalyticsRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[16];
    funcPtrs[0] = (void*)bmGameAnalyticsGetErrorString;
    funcPtrs[1] = (void*)bmGameAnalyticsGetError;
    funcPtrs[2] = (void*)bmGameAnalyticsAddBusinessEventWithoutReceipt;
    funcPtrs[3] = (void*)bmGameAnalyticsAddBusinessEvent;
    funcPtrs[4] = (void*)bmGameAnalyticsAddResourceEvent;
    funcPtrs[5] = (void*)bmGameAnalyticsAddProgressionEventWithScore;
    funcPtrs[6] = (void*)bmGameAnalyticsAddProgressionEvent;
    funcPtrs[7] = (void*)bmGameAnalyticsAddDesignEvent;
    funcPtrs[8] = (void*)bmGameAnalyticsAddDesignEventWithValue;
    funcPtrs[9] = (void*)bmGameAnalyticsAddErrorEvent;
    funcPtrs[10] = (void*)bmGameAnalyticsSetCustomDimension01;
    funcPtrs[11] = (void*)bmGameAnalyticsSetCustomDimension02;
    funcPtrs[12] = (void*)bmGameAnalyticsSetCustomDimension03;
    funcPtrs[13] = (void*)bmGameAnalyticsSetUserFacebookId;
    funcPtrs[14] = (void*)bmGameAnalyticsSetUserGender;
    funcPtrs[15] = (void*)bmGameAnalyticsSetUserBirthYear;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[16] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("bmGameAnalytics", funcPtrs, sizeof(funcPtrs), flags, bmGameAnalyticsInit, bmGameAnalyticsTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int bmGameAnalyticsStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&bmGameAnalyticsRegisterExt;
    return 0;
}

int g_bmGameAnalyticsVal = bmGameAnalyticsStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    bmGameAnalyticsRegisterExt();
}
#endif

#endif
