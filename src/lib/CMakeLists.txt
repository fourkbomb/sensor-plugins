cmake_minimum_required(VERSION 2.6)
project(sensor-hal CXX)

INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(sensor-hal_pkgs REQUIRED dlog libxml-2.0)

FOREACH(flag ${sensor-hal_pkgs_LDFLAGS})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
ENDFOREACH(flag)

FOREACH(flag ${sensor-hal_pkgs_CFLAGS})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
ENDFOREACH(flag)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})