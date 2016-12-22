# THANKS for initial guidance:
# https://code.tutsplus.com/tutorials/advanced-android-getting-started-with-the-ndk--mobile-2152
# original location:
# http://mobile.tutsplus.com/tutorials/android/ndk-tutorial/

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)  

LOCAL_LDLIBS := -llog
LOCAL_MODULE := sqlc-native-driver

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../sqlite-amalgamation

LOCAL_CFLAGS += -DSQLITE_TEMP_STORE=2
LOCAL_CFLAGS += -DSQLITE_THREADSAFE=1
LOCAL_CFLAGS += -DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS
LOCAL_CFLAGS += -DSQLITE_ENABLE_FTS4
LOCAL_CFLAGS += -DSQLITE_ENABLE_RTREE
LOCAL_CFLAGS += -DSQLITE_OMIT_BUILTIN_TEST
LOCAL_CFLAGS += -DSQLITE_OMIT_LOAD_EXTENSION

# Avoid "potential disruptive change" from 3.12.0 described at:
# - http://sqlite.org/releaselog/3_12_0.html
# - http://sqlite.org/pgszchng2016.html
LOCAL_CFLAGS += -DSQLITE_DEFAULT_PAGE_SIZE=1024
LOCAL_CFLAGS += -DSQLITE_DEFAULT_CACHE_SIZE=2000

LOCAL_SRC_FILES := ../native/sqlc_all.c

include $(BUILD_SHARED_LIBRARY)
