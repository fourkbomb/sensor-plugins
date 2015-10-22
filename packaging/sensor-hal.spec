Name:       sensor-hal
Summary:    Sensor HAL Plugins
Version:    1.0.0
Release:    0
Group:      System/Sensor HAL
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1:    sensor-hal.manifest

BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(libxml-2.0)

%define accel_state OFF
%define gyro_state OFF
%define proxi_state OFF
%define light_state OFF
%define geo_state OFF
%define pressure_state OFF
%define temperature_state OFF
%define ultraviolet_state OFF
%define rv_state OFF
%define bio_led_red_state OFF

%description
Sensor HAL Plugins

%package sensor-hal
Summary:    Sensor HAL Plugins
Group:      System/Sensor HAL Plugins
Requires:   %{name} = %{version}-%{release}

%description sensor-hal
Sensor HAL Plugins

%package -n sensor-hal-devel
Summary:    Sensor HAL Plugins library (devel)
Group:      System/Development
Requires:   %{name} = %{version}-%{release}

%description -n sensor-hal-devel
Sensor Plugin library (devel)

%prep
%setup -q
cp %{SOURCE1} .

cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DACCEL=%{accel_state} \
-DGYRO=%{gyro_state} -DPROXI=%{proxi_state} -DLIGHT=%{light_state} \
-DGEO=%{geo_state} -DPRESSURE=%{pressure_state} -DTEMPERATURE=%{temperature_state} \
-DRV=%{rv_state} -DULTRAVIOLET=%{ultraviolet_state} \
-DBIO_LED_RED=%{bio_led_red_state} \
-DLIBDIR=%{_libdir} -DINCLUDEDIR=%{_includedir}

%build
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install

%post -n sensor-hal -p /sbin/ldconfig

%postun -n sensor-hal -p /sbin/ldconfig

%files -n sensor-hal
%manifest sensor-hal.manifest
%attr(0644,root,root) /usr/etc/sensors.xml
%{_libdir}/libsensor-hal.so
%if %{accel_state} == "ON"
%{_libdir}/sensor-hal/libaccel_sensor_hal.so
%endif
%if %{gyro_state} == "ON"
%{_libdir}/sensor-hal/libgyro_sensor_hal.so
%endif
%if %{geo_state} == "ON"
%{_libdir}/sensor-hal/libgeo_sensor_hal.so
%endif
%if %{proxi_state} == "ON"
%{_libdir}/sensor-hal/libproxi_sensor_hal.so
%endif
%if %{light_state} == "ON"
%{_libdir}/sensor-hal/liblight_sensor_hal.so
%endif
%if %{pressure_state} == "ON"
%{_libdir}/sensor-hal/libpressure_sensor_hal.so
%endif
%if %{temperature_state} == "ON"
%{_libdir}/sensor-hal/libtemperature_sensor_hal.so
%endif
%if %{ultraviolet_state} == "ON"
%{_libdir}/sensor-hal/libultraviolet_sensor_hal.so
%endif
%if %{bio_led_red_state} == "ON"
%{_libdir}/sensor-hal/libbio_led_red_sensor_hal.so
%endif
%if %{rv_state} == "ON"
%{_libdir}/sensor-hal/librv_raw_sensor_hal.so
%endif



%files -n sensor-hal-devel
%{_includedir}/sensor-hal/cconfig.h
%{_includedir}/sensor-hal/csensor_config.h
%{_includedir}/sensor-hal/sensor_hal.h
%{_includedir}/sensor-hal/sf_common.h
%{_includedir}/sensor-hal/cbase_lock.h
%{_includedir}/sensor-hal/cmutex.h
%{_includedir}/sensor-hal/common.h
%{_includedir}/sensor-hal/sensor_common.h
%{_libdir}/libsensor-hal.so
%{_libdir}/pkgconfig/sensor-hal.pc

