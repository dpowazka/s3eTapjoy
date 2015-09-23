/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
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