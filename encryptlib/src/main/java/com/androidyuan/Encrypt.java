package com.androidyuan;

/**
 * Created by wei on 16-11-28.
 */

public class Encrypt {
    static{
        System.loadLibrary("JNIEncrypt");
    }

    public native static String MD5(String str);

    native String base64(String str);

}
