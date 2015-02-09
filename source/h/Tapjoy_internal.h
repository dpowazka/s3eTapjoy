/*
 * Internal header for the Tapjoy extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef TAPJOY_INTERNAL_H
#define TAPJOY_INTERNAL_H

#include "s3eTypes.h"
#include "Tapjoy.h"
#include "Tapjoy_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult TapjoyInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult TapjoyInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void TapjoyTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void TapjoyTerminate_platform();
s3eResult tapjoy_init_platform(const char* app_id, const char* secret_key);

s3eResult tapjoy_on_pause_platform();

s3eResult tapjoy_show_offers_platform();

s3eResult tapjoy_show_fullscreen_ad_platform();

int tapjoy_get_tap_points_platform();

int tapjoy_update_tap_points_platform();


#endif /* !TAPJOY_INTERNAL_H */