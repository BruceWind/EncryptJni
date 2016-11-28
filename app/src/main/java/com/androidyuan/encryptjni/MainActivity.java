package com.androidyuan.encryptjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;
import com.androidyuan.Encrypt;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toast(Encrypt.MD5("123"));
    }


    private void toast(String str)
    {

        Toast.makeText(this,str+"",Toast.LENGTH_LONG).show();
    }
}
