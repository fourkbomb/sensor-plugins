cmake_minimum_required(VERSION 2.6)
project(sensor_hal_src CXX)

include_directories(${CMAKE_SOURCE_DIR}/src/lib)
include_directories(${CMAKE_SOURCE_DIR}/src/interface)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


IF("${ACCEL}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/accel)
list (APPEND SRCS "plugins/accel/accel_sensor_hal.cpp")
ENDIF()
IF("${GYRO}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/gyro)
list (APPEND SRCS "plugins/gyro/gyro_sensor_hal.cpp")
ENDIF()
IF("${PROXI}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/proxi)
list (APPEND SRCS "plugins/proxi/proxi_sensor_hal.cpp")
ENDIF()
IF("${LIGHT}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/light)
list (APPEND SRCS "plugins/light/light_sensor_hal.cpp")
ENDIF()
IF("${GEO}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/geo)
list (APPEND SRCS "plugins/geo/geo_sensor_hal.cpp")
ENDIF()
IF("${PRESSURE}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/pressure)
list (APPEND SRCS "plugins/pressure/pressure_sensor_hal.cpp")
ENDIF()
IF("${TEMPERATURE}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/temperature)
list (APPEND SRCS "plugins/temperature/temperature_sensor_hal.cpp")
ENDIF()
IF("${ULTRAVIOLET}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/ultraviolet)
list (APPEND SRCS "plugins/ultraviolet/ultraviolet_sensor_hal.cpp")
ENDIF()
IF("${BIO_LED_RED}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/bio_led_red)
list (APPEND SRCS "plugins/bio_led_red/bio_led_red_sensor_hal.cpp")
ENDIF()
IF("${RV}" STREQUAL "ON")
include_directories(${CMAKE_SOURCE_DIR}/src/plugins/rotation_vector/rv_raw)
list (APPEND SRCS "plugins/rotation_vector/rv_raw/rv_raw_sensor_hal.cpp")
ENDIF()

add_subdirectory(lib)
add_subdirectory(interface)

configure_file( hal_module_create.cpp.in hal_module_create.cpp @ONLY)

add_library(sensor-hal SHARED
	hal_module_create.cpp
	${SRCS}
	)

SET_TARGET_PROPERTIES(
	sensor-hal
	PROPERTIES
	LINKER_LANGUAGE CXX
)

install(TARGETS sensor-hal DESTINATION ${CMAKE_INSTALL_LIBDIR})
