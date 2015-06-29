# see http://mobile.tutsplus.com/tutorials/android/ndk-tutorial/

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)  
LOCAL_LDLIBS := -llog
LOCAL_MODULE    := sqlg
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../sqlite-amalgamation
LOCAL_CFLAGS += -DSQLITE_TEMP_STORE=2 -DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_RTREE
LOCAL_SRC_FILES := ../native/sqlg_all.c
include $(BUILD_SHARED_LIBRARY)

