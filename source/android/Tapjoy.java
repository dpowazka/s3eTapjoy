/*
java implementation of the Tapjoy extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import android.content.SharedPreferences;
import com.tapjoy.TapjoyConnect;
import com.tapjoy.TapjoyNotifier;
import com.tapjoy.TapjoyEarnedPointsNotifier;
import com.tapjoy.TapjoyConnectNotifier;

import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

class Tapjoy
{
	private static final String TAP_POINTS_KEY = "tap_points";
	private int tap_points;
	private SharedPreferences settings;
	
	private final TapjoyNotifier tapjoy_notifier = new TapjoyNotifier() {
		public void getUpdatePoints(String currencyName, int pointTotal) {
			tap_points = pointTotal;
			System.out.println("[Warlings] Tapjoy points: " + tap_points);
			
			SharedPreferences.Editor editor = settings.edit();
			editor.putInt(TAP_POINTS_KEY, tap_points);
			editor.commit();
		}
			
		public void getUpdatePointsFailed(String error) {
		}
	};	
		
    public int tapjoy_init(String app_id, String secret_key)
    {
		settings = LoaderActivity.m_Activity.getSharedPreferences("com.warlings", 0);
		tap_points = settings.getInt(TAP_POINTS_KEY, 0);
		
		final TapjoyEarnedPointsNotifier earned_points_notifier = new TapjoyEarnedPointsNotifier() {
			public void earnedTapPoints(int amount) {
				tap_points += amount;
				System.out.println("[Warlings] Tapjoy points update: " + amount);
			}
		};
		
			
		
        TapjoyConnect.requestTapjoyConnect(LoaderActivity.m_Activity, app_id, secret_key, null, new TapjoyConnectNotifier() {
			@Override
			public void connectSuccess() {
				TapjoyConnect.getTapjoyConnectInstance().setEarnedPointsNotifier(earned_points_notifier);
				TapjoyConnect.getTapjoyConnectInstance().getTapPoints(tapjoy_notifier);
			}

			@Override
			public void connectFail() {
				
			}
		});
		
		return 0;
    }
	
    public int tapjoy_on_pause()
    {
		TapjoyConnect.getTapjoyConnectInstance().appPause();
        return 0;
    }
	
    public int tapjoy_show_offers()
    {
		TapjoyConnect.getTapjoyConnectInstance().showOffers();
        return 0;
    }
	
    public int tapjoy_show_fullscreen_ad()
    {
		TapjoyConnect.getTapjoyConnectInstance().showFullScreenAd();
        return 0;
    }
	
	 public int tapjoy_get_tap_points()
    {
        return tap_points;
    }
	
	 public int tapjoy_update_tap_points()
    {
		TapjoyConnect.getTapjoyConnectInstance().getTapPoints(tapjoy_notifier);
        return 0;
    }
}
