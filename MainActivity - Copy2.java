package com.example.thetravelapp;


import android.app.Activity;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {
	Button btPlay, btReservation, btPictures;
	MediaPlayer mpPlay;
	int Playing;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		btPlay = (Button) findViewById(R.id.btnPlay);
		btPlay.setOnClickListener(bPlay);
		btReservation = (Button) findViewById(R.id.btnDate);
		btReservation.setOnClickListener(bReservation);
		btPictures = (Button) findViewById(R.id.btnPictures);
		btPictures.setOnClickListener(bPictures);
		mpPlay = new MediaPlayer( );
		mpPlay = MediaPlayer.create(this, R.raw.ziadi);
		Playing = 0;
	}
	
	// To Open Pictures
	Button.OnClickListener bPictures = new Button.OnClickListener( ) {

		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			startActivity(new Intent(MainActivity.this, Pictures.class));
		}
		
	};
	
	// To Open Calendar
	Button.OnClickListener bReservation = new Button.OnClickListener( ) {

		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			startActivity(new Intent(MainActivity.this, Reservation.class));
			
		}
		
	};
	// To Open Song
	Button.OnClickListener bPlay = new Button.OnClickListener( ) {

		@Override
		public void onClick(View v) {
			// TODO Auto-generated method stub
			switch(Playing) {
			case 0:
				mpPlay.start( );
				Playing = 1;
				btPlay.setText("Pause Song");
				break;
			case 1:
				mpPlay.pause( );
				Playing = 0;
				btPlay.setText("Play Song");
				break;
			}
			
		}
		
	};

}
