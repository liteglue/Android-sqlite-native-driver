# Android sqlite native driver

Provides Android NDK build of sqlite3 (<http://sqlite.org/>, public domain) with a low-level JNI interface accessible from a single (singleton) single `SQLiteNative` class.

Based on [SQLiteGlue-core](https://github.com/sqlg/SQLiteGlue-core), which may be adapted for other Java platforms.

by Christopher J. Brody aka Chris Brody mailto: <brodybits@litehelpers.net>

License: UNLICENSE (public domain).

## About

Android-sqlite-native-driver provides the following items:
- single `SQLiteNative` class with native Java interface to an important subset of sqlite3 C functions
- automatic build of `sqlite-native-driver.jar` and `sqlite-native-driver-libs.zip` with sqlite3 component for major Android NDK targets (`armeabi` / `armeabi-v7a` / `x86` / `x86_64` / `arm64-v8a`), with sqlite3 component

This is accomplished by using [GlueGen](http://jogamp.org/gluegen/www/) around a simple wrapper C module.

This project is meant to help build a higher-level sqlite interface library, with the JNI layer completely isolated.

**NOTE:** This project references the `gluegentools` and `sqlite-amalgamation` subprojects, which are resolved by: $ `make init` (as described below).

**WARNING:** The sqlite database and statement handles that are returned by the `SQLiteNative` library functions are raw C pointer values (with `0x100000000` added). If someone uses a database or statement handle that is not valid, or no longer valid with the `SQLiteNative` library the behavior is undefined (may crash, for example). It is NOT recommended to use the API directly without understanding of how this library works internally.

FUTURE TODO: better documentation of API and some internal details

## SQLite build information

### SQLite version

    3.15.2

### SQLite build flags

- `-DSQLITE_THREADSAFE=1`
- `-DSQLITE_DEFAULT_MEMSTATUS=0`
- `-DSQLITE_OMIT_DECLTYPE`
- `-DSQLITE_OMIT_DEPRECATED`
- `-DSQLITE_OMIT_PROGRESS_CALLBACK`
- `-DSQLITE_OMIT_SHARED_CACHE`
- `-DSQLITE_TEMP_STORE=2`
- `-DSQLITE_OMIT_LOAD_EXTENSION`
- `-DSQLITE_ENABLE_FTS3`
- `-DSQLITE_ENABLE_FTS3_PARENTHESIS`
- `-DSQLITE_ENABLE_FTS4`
- `-DSQLITE_ENABLE_RTREE`
- `-DSQLITE_DEFAULT_PAGE_SIZE=1024`
- `-DSQLITE_DEFAULT_CACHE_SIZE=2000`

**NOTE:** Old default page/cache size values are used to avoid a "potentially disruptive change" described at: http://sqlite.org/pgszchng2016.html

## Major TODOs and limitations

- Automatic AAR build
- Document this project (again, perhaps in a blog post)
- Support BLOB type
- Some more SQLite API functions will be needed to rebuild the native sqlcipher library to replace the native libraries in the [@sqlcipher / android-database-sqlcipher](https://github.com/sqlcipher/android-database-sqlcipher) ([SQLCipher for Android](https://www.zetetic.net/sqlcipher/sqlcipher-for-android/)) project.

# Building

## Normal build

Initialize with the `gluegentools` and `sqlite-amalgamation` subprojects:

$ `make init`

Then to build:

$ `make`

## Regenerage Java & C glue code

$ `make regen`

# Testing

Tested with [Android-sqlite-connector](https://github.com/liteglue/Android-sqlite-connector).

