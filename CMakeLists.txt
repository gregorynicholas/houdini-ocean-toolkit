#
# Root CMakeLists.txt to build all the HVT tools
# 
cmake_minimum_required(VERSION 2.6)

project(Houdini_Ocean_Toolkit)

# run our helper process to grab the compile and link flags from hcustom

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules" )
execute_process(COMMAND hdk-config.py --notag --cmake=${PROJECT_SOURCE_DIR}/CMakeModules/FindHDK.cmake)

find_package(HDK)

set(CMAKE_INSTALL_PREFIX ${HDK_HIH_DIR})

# the 3rdparty libraries that I use can usually be found here ...
#set (CMAKE_FIND_ROOT_PATH  ${PROJECT_SOURCE_DIR}/../3rdparty)


add_subdirectory(src)

#
# packaging setup
#
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The Houdini Ocean Toolkit")
SET(CPACK_PACKAGE_VENDOR "Drew.Whitehouse@anu.edu.au")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0rc7")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
IF(WIN32 AND NOT UNIX)
SET(CPACK_GENERATOR "ZIP")
ELSE(WIN32 AND NOT UNIX)
SET(CPACK_GENERATOR "TGZ")
ENDIF(WIN32 AND NOT UNIX)

include(CPack)
