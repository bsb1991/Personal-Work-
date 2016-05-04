package com.example.thetravelapp;


import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Toast;

public class Pictures extends Activity {
	Integer[] Places = {R.drawable.one, R.drawable.two, R.drawable.three, R.drawable.four ,R.drawable.five};
	ImageView pic;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		GridView gr = (GridView)findViewById(R.id.gridView1);
		final ImageView pic= (ImageView)findViewById(R.id.imgLarge);
		gr.setAdapter(new ImageAdapter(this));
		gr.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				// TODO Auto-generated method stub
				Toast.makeText(getBaseContext(), "Select Picture "+ (position + 1),Toast.LENGTH_SHORT).show();
				pic.setImageResource(Places[position]);
			}
			
		});
	}
	public class ImageAdapter extends BaseAdapter {
		private Context context;

		public ImageAdapter(Pictures pictures) {
			// TODO Auto-generated constructor stub
			context=pictures;
		}

		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return Places.length;
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
			pic = new ImageView(context);
			pic.setImageResource(Places[position]);
			pic.setScaleType(ImageView.ScaleType.FIT_XY);
			pic.setLayoutParams(new GridView.LayoutParams(188,200));
			return pic;
		}
		
	}

}
