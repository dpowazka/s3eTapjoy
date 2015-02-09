/*
 * android-specific implementation of the Tapjoy extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "Tapjoy_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_tapjoy_init;
static jmethodID g_tapjoy_on_pause;
static jmethodID g_tapjoy_show_offers;
static jmethodID g_tapjoy_show_fullscreen_ad;
static jmethodID g_tapjoy_get_tap_points;
static jmethodID g_tapjoy_update_tap_points;

s3eResult TapjoyInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("Tapjoy");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_tapjoy_init = env->GetMethodID(cls, "tapjoy_init", "(Ljava/lang/String;Ljava/lang/String;)I");
    if (!g_tapjoy_init)
        goto fail;

    g_tapjoy_on_pause = env->GetMethodID(cls, "tapjoy_on_pause", "()I");
    if (!g_tapjoy_on_pause)
        goto fail;

    g_tapjoy_show_offers = env->GetMethodID(cls, "tapjoy_show_offers", "()I");
    if (!g_tapjoy_show_offers)
        goto fail;

    g_tapjoy_show_fullscreen_ad = env->GetMethodID(cls, "tapjoy_show_fullscreen_ad", "()I");
    if (!g_tapjoy_show_fullscreen_ad)
        goto fail;

    g_tapjoy_get_tap_points = env->GetMethodID(cls, "tapjoy_get_tap_points", "()I");
    if (!g_tapjoy_get_tap_points)
        goto fail;

    g_tapjoy_update_tap_points = env->GetMethodID(cls, "tapjoy_update_tap_points", "()I");
    if (!g_tapjoy_update_tap_points)
        goto fail;



    IwTrace(TAPJOY, ("TAPJOY init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(Tapjoy, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void TapjoyTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult tapjoy_init_platform(const char* app_id, const char* secret_key)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring app_id_jstr = env->NewStringUTF(app_id);
    jstring secret_key_jstr = env->NewStringUTF(secret_key);
    return (s3eResult)env->CallIntMethod(g_Obj, g_tapjoy_init, app_id_jstr, secret_key_jstr);
}

s3eResult tapjoy_on_pause_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_tapjoy_on_pause);
}

s3eResult tapjoy_show_offers_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_tapjoy_show_offers);
}

s3eResult tapjoy_show_fullscreen_ad_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (s3eResult)env->CallIntMethod(g_Obj, g_tapjoy_show_fullscreen_ad);
}

int tapjoy_get_tap_points_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_tapjoy_get_tap_points);
}

int tapjoy_update_tap_points_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_tapjoy_update_tap_points);
}
