/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "Tapjoy.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*tapjoy_init_t)(const char* app_id, const char* secret_key);
typedef  s3eResult(*tapjoy_on_pause_t)();
typedef  s3eResult(*tapjoy_show_offers_t)();
typedef  s3eResult(*tapjoy_show_fullscreen_ad_t)();
typedef        int(*tapjoy_get_tap_points_t)();
typedef        int(*tapjoy_update_tap_points_t)();

/**
 * struct that gets filled in by TapjoyRegister
 */
typedef struct TapjoyFuncs
{
    tapjoy_init_t m_tapjoy_init;
    tapjoy_on_pause_t m_tapjoy_on_pause;
    tapjoy_show_offers_t m_tapjoy_show_offers;
    tapjoy_show_fullscreen_ad_t m_tapjoy_show_fullscreen_ad;
    tapjoy_get_tap_points_t m_tapjoy_get_tap_points;
    tapjoy_update_tap_points_t m_tapjoy_update_tap_points;
} TapjoyFuncs;

static TapjoyFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x1d8ff2bc, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: Tapjoy");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x1d8ff2bc, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool TapjoyAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult tapjoy_init(const char* app_id, const char* secret_key)
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[0] func: tapjoy_init"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_tapjoy_init(app_id, secret_key);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult tapjoy_on_pause()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[1] func: tapjoy_on_pause"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_tapjoy_on_pause();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult tapjoy_show_offers()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[2] func: tapjoy_show_offers"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_tapjoy_show_offers();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult tapjoy_show_fullscreen_ad()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[3] func: tapjoy_show_fullscreen_ad"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_tapjoy_show_fullscreen_ad();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int tapjoy_get_tap_points()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[4] func: tapjoy_get_tap_points"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_tapjoy_get_tap_points();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int tapjoy_update_tap_points()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy[5] func: tapjoy_update_tap_points"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_tapjoy_update_tap_points();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
