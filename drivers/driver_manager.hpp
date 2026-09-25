#pragma once
#include "motor/motor.hpp"
#include "battery/battery_volts.hpp"

namespace drivers{
    extern battery_volts::BatteryVoltsDriver battery_driver;
    extern motor::Motor motor_left, motor_right;
    void init();
};
