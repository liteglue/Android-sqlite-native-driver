# see http://mobile.tutsplus.com/tutorials/android/ndk-tutorial/

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)  
LOCAL_LDLIBS := -llog
LOCAL_MODULE    := sqlg
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../sqlite-amalgamation
LOCAL_SRC_FILES := ../native/sqlg_all.c ../sqlite-amalgamation/sqlite3.c
include $(BUILD_SHARED_LIBRARY)

