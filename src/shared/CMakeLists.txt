cmake_minimum_required(VERSION 2.6)
project(sensor-plugins CXX)

INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(sensord-plugins_pkgs REQUIRED dlog libxml-2.0)

FOREACH(flag ${sensord-plugins_pkgs_LDFLAGS})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
ENDFOREACH(flag)

FOREACH(flag ${sensord-plugins_pkgs_CFLAGS})
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}")
ENDFOREACH(flag)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED
	cbase_lock.cpp
	cconfig.cpp
	cmutex.cpp
	common.cpp
	csensor_config.cpp
	sensor_hal.cpp
)

target_link_libraries(${PROJECT_NAME} ${sensord-plugins_pkgs_LDFLAGS} "-lrt -ldl")
configure_file(${PROJECT_NAME}.pc.in ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pc @ONLY)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${PROJECT_NAME}.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

install(FILES
	cconfig.h
	csensor_config.h
	sensor_hal.h
	sf_common.h
	cbase_lock.h
	cmutex.h
	common.h
	sensor_common.h
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)
