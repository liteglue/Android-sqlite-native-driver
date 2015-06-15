
all: ndkbuild

init:
	git submodule update --init

regen:
	java -cp gluegentools/antlr.jar:gluegentools/gluegen.jar com.jogamp.gluegen.GlueGen -I. -Ecom.jogamp.gluegen.JavaEmitter -CSQLiteGlue.cfg native/sqlg.h
	sed -i.orig 's/^import/\/\/import/' java/org/sqlg/SQLiteGlue.java

# NOTE: adding v (verbose) flag for the beginning stage:
ndkbuild:
	cd jni
	ndk-build

clean:
	rm -rf obj
	rm -rf libs

