# Android sqlite native driver

Provides a native build of sqlite with a low-level interface for Android libraries.

Based on [SQLiteGlue-core](https://github.com/sqlg/SQLiteGlue-core), which may be adapted for other Java platforms.

by Christopher J. Brody aka Chris Brody mailto: brodybits@litehelpers.net

License: UNLICENSE (public domain).

## About

Android-sqlite-native-driver provides:
- single `SQLiteNative` class with native Java interface to _an important_ subset of sqlite C functions
- automatic build of `sqlite-native-driver-libs.zip`, with native sqlite library build for major Android targets (`armeabi`, `armeabi-v7a`, `x86`, `x86_64`) that is accessible from the native Java interface

This is accomplished by using [GlueGen](http://jogamp.org/gluegen/www/) around a simple wrapper C module.

This project is meant to help build a higher-level sqlite interface library, with the JNI layer completely isolated.

**NOTE:** This project references the `gluegentools` and `sqlite-amalgamation` subprojects, which are resolved by: $ `make init` (as described below).

**WARNING:** The sqlite database and statement handles that are returned by the `SQLiteNative` library functions are raw C pointer values (with `0x100000000` added). If someone uses a sqlite database or statement handle that is not valid, or no longer valid with the `SQLiteNative` library the behavior is undefined (such as a crash). It is *NOT* recommended to use this API directly unless you really understand how this library works internally.

TBD API and some internal details (probably in a blog post)

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

