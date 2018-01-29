
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := JNIEncrypt
LOCAL_SRC_FILES := encrypt.c  \
  base64.c \
  base64.h  \
  md5.c \
  md5.h

LOCAL_CFLAGS := -fvisibility=hidden   -mllvm -sub -mllvm -fla -mllvm -bcf

# LOCAL_SHARED_LIBRARIES := liblog libcutils
LOCAL_LDLIBS    := -llog
LOCAL_CFLAGS="-std=c99"

include $(BUILD_SHARED_LIBRARY)

# include $(BUILD_EXECUTABLE)
