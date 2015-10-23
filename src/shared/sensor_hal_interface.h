/*
 * libsensord-share
 *
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef _SENSOR_HAL_INTERFACE_H_
#define _SENSOR_HAL_INTERFACE_H_

#include <sensor_hal.h>

class sensor_hal_interface : public sensor_hal
{
public:
	sensor_hal_interface();
	virtual ~sensor_hal_interface();

	virtual std::string get_model_id(void) = 0;
	virtual sensor_hal_type_t get_type(void) = 0;
	virtual bool enable(void) = 0;
	virtual bool disable(void) = 0;
	virtual bool is_data_ready(bool wait) = 0;
	virtual bool set_interval(unsigned long val) = 0;
	virtual int get_sensor_data(sensor_data_t &data) = 0;
	virtual bool get_properties(sensor_properties_s &properties) = 0;
};
#endif /*_SENSOR_HAL_INTERFACE_H_*/
