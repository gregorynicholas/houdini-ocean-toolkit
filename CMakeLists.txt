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
