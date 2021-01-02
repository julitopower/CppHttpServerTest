cmake_minimum_required(VERSION 3.2)

project(CPPHTTPSERVER)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MHD libmicrohttpd)

if (NOT ${MHD_FOUND})
  message(FATAL_ERROR "Could not find libmicrohttpd")
endif()

find_path(MHD_INCLUDE_DIRS microhttpd.h)
find_library(MHD_LIBRARIES NAMES libmicrohttpd)

include_directories(${MHD_INCLUDE_DIRS} server) 

add_subdirectory(bin)
add_subdirectory(server) 
