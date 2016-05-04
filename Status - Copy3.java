package net.androidbootcamp.clearjetrewards;

import android.R;
import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.widget.ImageView;
import android.widget.TextView;

public class Status extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.status);
		TextView result = (TextView)findViewById(R.id.txtResult);
		ImageView image=(ImageView)findViewById(R.id.imgStatus);
		SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(this);
		String strFlier = sharedPref.getString("key1", "");
		int intMilage = sharedPref.getInt("key2", 0);
		
		if (intMilage >= 75000) {
			image.setImageResource(R.drawable.gold);
			result.setText(strFlier + " has reached Gold status with " + intMilage + "miles");
		}
		else if (intMilage >= 50000) {
			image.setImageResource(R.drawable.silver);
			result.setText(strFlier + " has reached Silver status with " + intMilage + "miles");
	}
		else if (intMilage >= 25000) {
			image.setImageResource(R.drawable.bronze);
			result.setText(strFlier + " has reached bronze status with " + intMilage + "miles");
		}
		else{
			result.setText("You have not reached an award level");
		}
		

}
}

