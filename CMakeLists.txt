# Declare CMAKE minimum version
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

# Set your project name
PROJECT (CPPHTTPSERVER)

# Make sure that PkgConfig is avilable. This package will help
# us finding other packages
FIND_PACKAGE (PkgConfig REQUIRED)

PKG_CHECK_MODULES (MHD libmicrohttpd)

IF (NOT ${MHD_FOUND})
  MESSAGE(FATAL_ERROR "Could not find libmicrohttpd")
ENDIF()

FIND_PATH (MHD_INCLUDE_DIRS microhttpd.h)
FIND_LIBRARY (MHD_LIBRARIES NAMES libmicrohttpd)

INCLUDE_DIRECTORIES (${MHD_INCLUDE_DIRS}) 

# Make sure Boost is available
FIND_PACKAGE(Boost REQUIRED)

# Make sure JsonCpp is available
PKG_CHECK_MODULES(JSONCPP jsoncpp)

ADD_SUBDIRECTORY (bin)
ADD_SUBDIRECTORY (server) 