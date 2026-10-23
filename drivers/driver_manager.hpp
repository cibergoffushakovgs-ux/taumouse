#pragma once
#include "motor/motor.hpp"
#include "battery/battery_volts.hpp"
#include "encoder/encoder.hpp"
namespace drivers{
    extern battery_volts::BatteryVoltsDriver battery_driver;
    extern motor::Motor motor_left, motor_right;
    extern encoder::Encoder encoder_left, encoder_right;
    
    void init();
};
