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

//        toast(Encrypt.getMD5("123"));

        toast(
                "native: "+Encrypt.Base64encode("你大爷")
                +" \n java:"+
                Encrypt.javaBase64Encode("你大爷")
        );
    }


    private void toast(String str)
    {
        Toast.makeText(this,str+"",Toast.LENGTH_LONG).show();
    }
}
