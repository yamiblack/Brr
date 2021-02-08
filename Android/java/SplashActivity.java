package com.microsoft.cognitiveservices.speech.samples.sdkdemo;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.widget.Toast;


public class SplashActivity extends AppCompatActivity {
    private final int SPLASH_TIME = 1500;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(getApplication(), MainActivity.class));
                SplashActivity.this.finish();
            }
        }, SPLASH_TIME);

    }

}
