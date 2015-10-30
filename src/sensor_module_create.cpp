#define ACCEL strcmp("@ACCEL@", "ON")
#define BIO_LED_RED strcmp("@BIO_LED_RED@", "ON")
#define GEO strcmp("@GEO@", "ON")
#define GYRO strcmp("@GYRO@", "ON")
#define LIGHT strcmp("@LIGHT@", "ON")
#define PRESSURE strcmp("@PRESSURE@", "ON")
#define PROXI strcmp("@PROXI@", "ON")
#define RV_RAW strcmp("@RV_RAW@", "ON")
#define TEMPERATURE strcmp("@TEMPERATURE@", "ON")
#define ULTRAVIOLET strcmp("@ULTRAVIOLET@", "ON")

#if $ACCEL == 1
#include <accel_sensor_hal.h>
#endif
#if $BIO_LED_RED == 1
#include <bio_led_red_sensor_hal.h>
#endif
#if $GEO == 1
#include <geo_sensor_hal.h>
#endif
#if $GYRO == 1
#include <gyro_sensor_hal.h>
#endif
#if $LIGHT == 1
#include <light_sensor_hal.h>
#endif
#if $PRESSURE == 1
#include <pressure_sensor_hal.h>
#endif
#if $PROXI == 1
#include <proxi_sensor_hal.h>
#endif
#if $RV_RAW == 1
#include <rv_raw_sensor_hal.h>
#endif
#if $TEMPERATURE == 1
#include <temperature_sensor_hal.h>
#endif
#if $ULTRAVIOLET == 1
#include <ultraviolet_sensor_hal.h>
#endif

#include <sensor_common.h>

extern "C" sensor_module* create(void)
{
	sensor_module *module = new(std::nothrow) sensor_module;
	retvm_if(!module, NULL, "Failed to allocate memory");

#if $ACCEL == 1
	accel_sensor_hal *accel_sensor = NULL;
	try {
		accel_sensor = new(std::nothrow) accel_sensor_hal;
	} catch (int err) {
		ERR("Failed to create accel_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!accel_sensor)
		module->sensors.push_back(accel_sensor);
#endif

#if $BIO_LED_RED == 1
	bio_led_red_sensor_hal *bio_led_red_sensor = NULL;
	try {
		bio_led_red_sensor = new(std::nothrow) bio_led_red_sensor_hal;
	} catch (int err) {
		ERR("Failed to create bio_led_red_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!bio_led_red_sensor)
		module->sensors.push_back(bio_led_red_sensor);

#endif
#if $GEO == 1
	geo_sensor_hal *geo_sensor = NULL;
	try {
		geo_sensor = new(std::nothrow) geo_sensor_hal;
	} catch (int err) {
		ERR("Failed to create geo_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!geo_sensor)
		module->sensors.push_back(geo_sensor);

#endif
#if $GYRO == 1
	gyro_sensor_hal *gyro_sensor = NULL;
	try {
		gyro_sensor = new(std::nothrow) gyro_sensor_hal;
	} catch (int err) {
		ERR("Failed to create gyro_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!gyro_sensor)
		module->sensors.push_back(gyro_sensor);

#endif
#if $LIGHT == 1
	light_sensor_hal *light_sensor = NULL;
	try {
		light_sensor = new(std::nothrow) light_sensor_hal;
	} catch (int err) {
		ERR("Failed to create light_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!light_sensor)
		module->sensors.push_back(light_sensor);

	#endif
#if $PRESSURE == 1
	pressure_sensor_hal *pressure_sensor = NULL;
	try {
		pressure_sensor = new(std::nothrow) pressure_sensor_hal;
	} catch (int err) {
		ERR("Failed to create pressure_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!pressure_sensor)
		module->sensors.push_back(pressure_sensor);

#endif
#if $PROXI == 1
	proxi_sensor_hal *proxi_sensor = NULL;
	try {
		proxi_sensor = new(std::nothrow) proxi_sensor_hal;
	} catch (int err) {
		ERR("Failed to create proxi_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!proxi_sensor)
		module->sensors.push_back(proxi_sensor);

#endif
#if $RV_RAW == 1
	rv_raw_sensor_hal *rv_raw_sensor = NULL;
	try {
		rv_raw_sensor = new(std::nothrow) rv_raw_sensor_hal;
	} catch (int err) {
		ERR("Failed to create rv_raw_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!rv_raw_sensor)
		module->sensors.push_back(rv_raw_sensor);

#endif
#if $TEMPERATURE == 1

	temperature_sensor_hal *temperature_sensor = NULL;
	try {
		temperature_sensor = new(std::nothrow) temperature_sensor_hal;
	} catch (int err) {
		ERR("Failed to create temperature_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!temperature_sensor)
		module->sensors.push_back(temperature_sensor);

#endif
#if $ULTRAVIOLET == 1
	ultraviolet_sensor_hal *ultraviolet_sensor = NULL;
	try {
		ultraviolet_sensor = new(std::nothrow) ultraviolet_sensor_hal;
	} catch (int err) {
		ERR("Failed to create ultraviolet_sensor_hal module, err: %d, cause: %s", err, strerror(err));
	}
	if (!ultraviolet_sensor)
		module->sensors.push_back(ultraviolet_sensor);
#endif


	return module;
}
