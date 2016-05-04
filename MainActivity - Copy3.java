package net.androidbootcamp.clearjetrewards;

import android.R;
import android.support.v7.app.ActionBarActivity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;


public class MainActivity extends ActionBarActivity {
	String strName;
	int intMiles;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText name = (EditText)findViewById(R.id.txtName);
        final EditText miles = (EditText) findViewById(R.id.txtMiles);
        Button btStatus = (Button) findViewById(R.id.btnStatus);
        final SharedPreferences sharedPref =PreferenceManager.getDefaultSharedPreferences(this);
        btStatus.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				strName = name.getText().toString();
				intMiles = Integer.parseInt(miles.getText().toString());
				SharedPreferences.Editor editor = sharedPref.edit();
				editor.putString("key1", strName);
				editor.putInt("key2", intMiles);
				editor.commit();
				startActivity(new Intent(MainActivity.this, Status.class));
			}
        	
        });
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
