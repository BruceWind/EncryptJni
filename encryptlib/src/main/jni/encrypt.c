#include <jni.h>
#include<stdio.h>
#include<string.h>
#include <android/log.h>
#include "md5.h"
#include "base64.h"

#define LOG_TAG "MD5"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


// 把java的字符串转换成c的字符串,使用反射
char *Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    // 1:先找到字节码文件
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
    // 2:通过字节码文件找到方法ID
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    // 3:通过方法id，调用方法
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    // 4:得到数据的长度
    jsize alen = (*env)->GetArrayLength(env, barr);
    // 5：得到数据的首地址
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    // 6:得到C语言的字符串
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0); //
    return rtn;
}


JNIEXPORT jstring JNICALL Java_com_androidyuan_Encrypt_MD5(
        JNIEnv *env,
        jobject instance,
        jstring jInfo
) {

//    char* cstr = Jstring2CStr(env, jInfo);
    const char *cstr = (*env)->GetStringUTFChars(env, jInfo, 0);

    MD5_CTX context = {0};
    MD5Init(&context);
    MD5Update(&context, cstr, strlen(cstr));
    unsigned char dest[16] = {0};
    MD5Final(dest, &context);
    (*env)->ReleaseStringUTFChars(env, jInfo, cstr);

    int i;
    char destination[32] = {0};
    for (i = 0; i < 16; i++) {
        sprintf(destination, "%s%02x", destination, dest[i]);
    }
    LOGI("%s", destination);
    return (*env)->NewStringUTF(env, destination);
}


JNIEXPORT jstring JNICALL Java_com_androidyuan_Encrypt_base64Encode(
        JNIEnv *env,
        jclass type,
        jstring olds) {

    const char *old_str = (*env)->GetStringUTFChars(env, olds, 0);

    (*env)->ReleaseStringUTFChars(env, olds, old_str);

    return (*env)->NewStringUTF(env, b64_encode(old_str, strlen(old_str)));
}


JNIEXPORT jstring JNICALL Java_com_androidyuan_Encrypt_base64Decode(
        JNIEnv *env,
        jclass type,
        jstring str_
) {
    const char *str = (*env)->GetStringUTFChars(env, str_, 0);

    (*env)->ReleaseStringUTFChars(env, str_, str);

    return (*env)->NewStringUTF(env, b64_decode(str, strlen(str)));
}