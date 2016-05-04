package com.example.thetravelapp;

import java.text.DateFormat;
import java.util.Calendar;


import android.app.Activity;
import android.app.DatePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TextView;

public class Reservation extends Activity {
	private TextView reservation;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		reservation = (TextView) findViewById(R.id.txtReservation);
		Button btDate = (Button) findViewById(R.id.btnDate);
		btDate.setOnClickListener(new View.OnClickListener( ) {

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				new DatePickerDialog(Reservation.this, d, c.get(Calendar.YEAR),c.get(Calendar.MONTH), c.get(Calendar.DAY_OF_MONTH)).show();
				
			}
			
		});
	}
	Calendar c = Calendar.getInstance();
	DateFormat fmtDate = DateFormat.getDateInstance();
	DatePickerDialog.OnDateSetListener d = new DatePickerDialog.OnDateSetListener() {

		@Override
		public void onDateSet(DatePicker view, int year, int monthOfYear,
				int dayOfMonth) {
			// TODO Auto-generated method stub
			c.set(Calendar.YEAR, year);
			c.set(Calendar.MONTH, monthOfYear);
			c.set(Calendar.DAY_OF_MONTH, dayOfMonth);
			reservation.setText("Your reservaton is set for " +fmtDate.format(c.getTime()));
			
		}
		
	};

}
