package com.androidyuan;

import android.util.Base64;

import java.nio.charset.Charset;
import java.security.MessageDigest;

/**
 * Created by wei on 16-11-28.
 */

public class Encrypt {

    static{
        System.loadLibrary("JNIEncrypt");
    }

    public native static String MD5(String str);

    public static String javaMD5(String info) {
        try {
            MessageDigest md5 = MessageDigest.getInstance("MD5");
            md5.update(info.getBytes("UTF-8"));
            byte[] encryption = md5.digest();

            StringBuffer strBuf = new StringBuffer();
            for (int i = 0; i < encryption.length; i++) {
                if (Integer.toHexString(0xff & encryption[i]).length() == 1) {
                    strBuf.append("0").append(Integer.toHexString(0xff & encryption[i]));
                } else {
                    strBuf.append(Integer.toHexString(0xff & encryption[i]));
                }
            }
            return strBuf.toString();
        } catch (Exception e) {
            return "";
        }
    }


    public static native String base64Encode(String str);

    public static native String base64Decode(String str);


    public static String javaBase64Encode(String str)
    {
        return android.util.Base64.encodeToString(str.getBytes(), Base64.DEFAULT);
    }


    public static String javaBase64Decode(String str)
    {
        return new String(android.util.Base64.decode(str.getBytes(), Base64.DEFAULT));
    }

}
