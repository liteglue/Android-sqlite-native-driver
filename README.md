# SQLiteGlue

Android &amp; other Java native glue interface to sqlite using Gluegen.

Unlicense (public domain).

## About

SQLiteGlue provides the basic functions necessary to use sqlite from an Android or other
Java application over JNI (Java native interface). This is accomplished by using
[GlueGen](http://jogamp.org/gluegen/www/) around a simple wrapper C module.

TBD API & some internal details

# Building

## First step

To include the `gluegentools` & `sqlite-amalgamation` subprojects: $ `make init`

## Normal build

$ `make`

## Regenerage Java & C glue code

$ `make regen`

# Adaptations & extensions

TBD

