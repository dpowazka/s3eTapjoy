/*
Generic implementation of the Tapjoy extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "Tapjoy_internal.h"
s3eResult TapjoyInit()
{
    //Add any generic initialisation code here
    return TapjoyInit_platform();
}

void TapjoyTerminate()
{
    //Add any generic termination code here
    TapjoyTerminate_platform();
}

s3eResult tapjoy_init(const char* app_id, const char* secret_key)
{
	return tapjoy_init_platform(app_id, secret_key);
}

s3eResult tapjoy_on_pause()
{
	return tapjoy_on_pause_platform();
}

s3eResult tapjoy_show_offers()
{
	return tapjoy_show_offers_platform();
}

s3eResult tapjoy_show_fullscreen_ad()
{
	return tapjoy_show_fullscreen_ad_platform();
}

int tapjoy_get_tap_points()
{
	tapjoy_get_tap_points_platform();
}

int tapjoy_update_tap_points()
{
	return tapjoy_update_tap_points_platform();
}
