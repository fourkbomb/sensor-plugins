Name:       sensor-plugins
Summary:    Sensor HAL Plugins
Version:    1.0.0
Release:    0
Group:      System/Sensor Plugins
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Source1:    sensor-plugins.manifest

BuildRequires:  cmake
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(libxml-2.0)

%define accel_state ON
%define gyro_state ON
%define proxi_state ON
%define light_state ON
%define geo_state ON
%define pressure_state ON
%define temperature_state ON
%define ultraviolet_state OFF
%define rv_state OFF
%define bio_led_red_state OFF

%description
Sensor HAL Plugins

%package sensor-plugins
Summary:    Sensor HAL Plugins
Group:      System/Sensor HAL Plugins
Requires:   %{name} = %{version}-%{release}

%description sensor-plugins
Sensor HAL Plugins

%package -n sensor-plugins-devel
Summary:    Sensor Plugins library (devel)
Group:      System/Development
Requires:   %{name} = %{version}-%{release}

%description -n sensor-plugins-devel
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

%post -n sensor-plugins -p /sbin/ldconfig

%postun -n sensor-plugins -p /sbin/ldconfig

%files -n sensor-plugins
%manifest sensor-plugins.manifest
%attr(0644,root,root) /usr/etc/sensors.xml
%{_libdir}/libsensor-plugins.so
%if %{accel_state} == "ON"
%{_libdir}/sensord-plugins/libaccel_sensor_hal.so
%endif
%if %{gyro_state} == "ON"
%{_libdir}/sensord-plugins/libgyro_sensor_hal.so
%endif
%if %{geo_state} == "ON"
%{_libdir}/sensord-plugins/libgeo_sensor_hal.so
%endif
%if %{proxi_state} == "ON"
%{_libdir}/sensord-plugins/libproxi_sensor_hal.so
%endif
%if %{light_state} == "ON"
%{_libdir}/sensord-plugins/liblight_sensor_hal.so
%endif
%if %{pressure_state} == "ON"
%{_libdir}/sensord-plugins/libpressure_sensor_hal.so
%endif
%if %{temperature_state} == "ON"
%{_libdir}/sensord-plugins/libtemperature_sensor_hal.so
%endif
%if %{ultraviolet_state} == "ON"
%{_libdir}/sensord-plugins/libultraviolet_sensor_hal.so
%endif
%if %{bio_led_red_state} == "ON"
%{_libdir}/sensord-plugins/libbio_led_red_sensor_hal.so
%endif


%files -n sensor-plugins-devel
%{_includedir}/sensor-plugins/cconfig.h
%{_includedir}/sensor-plugins/csensor_config.h
%{_includedir}/sensor-plugins/sensor_hal.h
%{_includedir}/sensor-plugins/sf_common.h
%{_includedir}/sensor-plugins/cbase_lock.h
%{_includedir}/sensor-plugins/cmutex.h
%{_includedir}/sensor-plugins/common.h
%{_includedir}/sensor-plugins/sensor_common.h
%{_libdir}/libsensor-plugins.so
%{_libdir}/pkgconfig/sensor-plugins.pc

