# SQLiteGlue

Android &amp; other Java native glue interface to sqlite using Gluegen.

Unlicense (public domain).

## About

SQLiteGlue provides the basic functions necessary to use sqlite from an Android or other
Java application over JNI (Java native interface). This is accomplished by using
[GlueGen](http://jogamp.org/gluegen/www/) around a simple wrapper C module.

TBD API & some internal details

**NOTE:** This project references the `gluegentools` & `sqlite-amalgamation` subproject, which are resolved by: $ `make init`

# Building

## Normal build

Initialize with subprojects:

$ `make init`

Then to build:

$ `make`

## Regenerage Java & C glue code

$ `make regen`

# Adaptations & extensions

TBD

