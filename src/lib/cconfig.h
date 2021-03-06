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

#ifndef _CCONFIG_H_
#define _CCONFIG_H_

#include <string>
#include <unordered_map>
#include <sensor_logs.h>

class cconfig
{
protected:
	virtual bool load_config(const std::string& config_path) = 0;

	std::string m_device_id;
public:
	cconfig();
	virtual ~cconfig();

	bool get_device_id(void);

};

#endif /* _CCONFIG_H_ */
