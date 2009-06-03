
#
#    Locate the HDK environment
#
# This module defines 
# HDK_FOUND,
# HDK_CXX_COMPILER
# HDK_INCLUDE_DIRS,
# HDK_DEFINITIONS,
# HDK_LIBRARY_DIRS,
# HDK_LIBRARIES,
# HDK_DSO_INSTALL_DIR
#
# For OSX, we have the following as well ...
#
# HDK_FRAMEWORK_DIRS,
# HDK_FRAMEWORKS,
#

SET(HDK_FOUND 1)

set(HDK_CXX_COMPILER g++)
set(CMAKE_OSX_ARCHITECTURES x86_64)
set(HDK_INCLUDE_DIRS /Library/Frameworks/Houdini.framework/Versions/Current/Resources/toolkit/include /Library/Frameworks/Houdini.framework/Versions/Current/Resources/toolkit/include/htools)

# the following are for compiling dso's
set(HDK_DEFINITIONS -arch x86_64 -DVERSION=\"10.0.295\" -DDLLEXPORT= -D_GNU_SOURCE -DMBSD -DMBSD_COCOA -DMBSD_INTEL -DAMD64 -DSIZEOF_VOID_P=8 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DGCC4 -DGCC3 -DMAKING_DSO -Wno-deprecated -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -fPIC -O2 -D__UT_DSOVersion__)
set(HDK_LIBRARY_DIRS /Library/Frameworks/Houdini.framework/Versions/10.0.295/Libraries /Library/Frameworks/Houdini.framework/Versions/Current/Resources/Frameworks/Houdini.framework/Versions/10.0.295/Libraries)
set(HDK_FRAMEWORK_DIRS /Library/Frameworks/Houdini.framework/Versions/Current/Resources/Frameworks)
set(HDK_FRAMEWORKS OpenGL Cocoa Houdini)
FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
FIND_LIBRARY(COCOA_LIBRARY Cocoa)
FIND_LIBRARY(HOUDINI_LIBRARY Houdini)
set(HDK_LIBRARIES ${OPENGL_LIBRARY} ${COCOA_LIBRARY} ${HOUDINI_LIBRARY})
set(HDK_HIH_DIR /Users/drw900/Library/Preferences/houdini/10.0)


# the following are for compiling dso's
set(HDK_STANDALONE_DEFINITIONS -arch x86_64 -DVERSION=\"10.0.295\" -DDLLEXPORT= -D_GNU_SOURCE -DMBSD -DMBSD_COCOA -DMBSD_INTEL -DAMD64 -DSIZEOF_VOID_P=8 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DGCC4 -DGCC3 -Wno-deprecated -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -fPIC -O2 -D__UT_DSOVersion__)
set(HDK_STANDALONE_LIBRARY_DIRS /Library/Frameworks/Houdini.framework/Versions/Current/Resources/dsolib /Library/Frameworks/Houdini.framework/Versions/Current/Resources/python/lib /Library/Frameworks/Houdini.framework/Versions/10.0.295/Libraries /Library/Frameworks/Houdini.framework/Versions/Current/Resources/Frameworks/Houdini.framework/Versions/10.0.295/Libraries)
set(HDK_STANDALONE_FRAMEWORK_DIRS /Library/Frameworks/Houdini.framework/Versions/Current/Resources/Frameworks)
set(HDK_STANDALONE_FRAMEWORKS Houdini OpenGL Cocoa)
FIND_LIBRARY(HOUDINI_LIBRARY Houdini)
FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
FIND_LIBRARY(COCOA_LIBRARY Cocoa)
set(HDK_STANDALONE_LIBRARIES ${HOUDINI_LIBRARY} ${OPENGL_LIBRARY} ${COCOA_LIBRARY} python2.5)
