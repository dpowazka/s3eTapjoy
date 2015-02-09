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
#include "Tapjoy_autodefs.h"
#include "s3eEdk.h"
#include "Tapjoy.h"
//Declarations of Init and Term functions
extern s3eResult TapjoyInit();
extern void TapjoyTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static s3eResult tapjoy_init_wrap(const char* app_id, const char* secret_key)
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_init"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_init, 2, app_id, secret_key);
}

static s3eResult tapjoy_on_pause_wrap()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_on_pause"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_on_pause, 0);
}

static s3eResult tapjoy_show_offers_wrap()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_show_offers"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_show_offers, 0);
}

static s3eResult tapjoy_show_fullscreen_ad_wrap()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_show_fullscreen_ad"));
    return (s3eResult)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_show_fullscreen_ad, 0);
}

static int tapjoy_get_tap_points_wrap()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_get_tap_points"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_get_tap_points, 0);
}

static int tapjoy_update_tap_points_wrap()
{
    IwTrace(TAPJOY_VERBOSE, ("calling Tapjoy func on main thread: tapjoy_update_tap_points"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)tapjoy_update_tap_points, 0);
}

#define tapjoy_init tapjoy_init_wrap
#define tapjoy_on_pause tapjoy_on_pause_wrap
#define tapjoy_show_offers tapjoy_show_offers_wrap
#define tapjoy_show_fullscreen_ad tapjoy_show_fullscreen_ad_wrap
#define tapjoy_get_tap_points tapjoy_get_tap_points_wrap
#define tapjoy_update_tap_points tapjoy_update_tap_points_wrap

#endif

void TapjoyRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[6];
    funcPtrs[0] = (void*)tapjoy_init;
    funcPtrs[1] = (void*)tapjoy_on_pause;
    funcPtrs[2] = (void*)tapjoy_show_offers;
    funcPtrs[3] = (void*)tapjoy_show_fullscreen_ad;
    funcPtrs[4] = (void*)tapjoy_get_tap_points;
    funcPtrs[5] = (void*)tapjoy_update_tap_points;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[6] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("Tapjoy", funcPtrs, sizeof(funcPtrs), flags, TapjoyInit, TapjoyTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int TapjoyStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&TapjoyRegisterExt;
    return 0;
}

int g_TapjoyVal = TapjoyStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    TapjoyRegisterExt();
}
#endif

#endif