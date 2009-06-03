
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
set(HDK_INCLUDE_DIRS /opt/hfs10.0.249.5/toolkit/include /opt/hfs10.0.249.5/toolkit/include/htools)

# the following are for compiling dso's
set(HDK_DEFINITIONS -m64 -DVERSION=\"10.0.249.5\" -DDLLEXPORT= -D_GNU_SOURCE -DLINUX -DAMD64 -DSIZEOF_VOID_P=8 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DGCC4 -DGCC3 -DMAKING_DSO -Wno-deprecated -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -fPIC -O2 -D__UT_DSOVersion__)
set(HDK_LIBRARY_DIRS /usr/X11R6/lib)
set(HDK_FRAMEWORK_DIRS )
set(HDK_FRAMEWORKS )
set(HDK_LIBRARIES GLU GL X11 Xext Xi dl)
set(HDK_HIH_DIR /home/drw900/houdini10.0)


# the following are for compiling dso's
set(HDK_STANDALONE_DEFINITIONS -m64 -DVERSION=\"10.0.249.5\" -DDLLEXPORT= -D_GNU_SOURCE -DLINUX -DAMD64 -DSIZEOF_VOID_P=8 -DSESI_LITTLE_ENDIAN -DENABLE_THREADS -DUSE_PTHREADS -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DGCC4 -DGCC3 -Wno-deprecated -Wall -W -Wno-parentheses -Wno-sign-compare -Wno-reorder -Wno-uninitialized -Wunused -Wno-unused-parameter -fPIC -O2 -D__UT_DSOVersion__)
set(HDK_STANDALONE_LIBRARY_DIRS /opt/hfs10.0.249.5/dsolib /opt/hfs10.0.249.5/python/lib /usr/X11R6/lib)
set(HDK_STANDALONE_FRAMEWORK_DIRS )
set(HDK_STANDALONE_FRAMEWORKS )
set(HDK_STANDALONE_LIBRARIES pthread HoudiniUI HoudiniOPZ HoudiniOP3 HoudiniOP2 HoudiniOP1 HoudiniSIM HoudiniGEO HoudiniPRM HoudiniUT python2.5 GLU GL X11 Xext Xi dl)
