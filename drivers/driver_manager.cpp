#include "driver_manager.hpp"
#include <Arduino.h>

namespace drivers
{
battery_volts::BatteryVoltsParams bat_params = {
    .scale = 2.0,
    .pin = A7

};
battery_volts::BatteryVoltsDriver battery_driver(bat_params);
float get_volts(){
return battery_driver.get_volts();
};
motor::motorParams motor_left_params = {
    .dirPin = 7,
    .pwmPin = 9,
    .polarity = 1,
    .get_voltage = get_volts};

motor::motorParams motor_right_params = {
    .dirPin = 8,
    .pwmPin = 10,
    .polarity = 0,
    .get_voltage = get_volts};

motor::Motor motor_left(motor_left_params);
motor::Motor motor_right(motor_right_params);

void init(){
    motor_left.init();
    motor_right.init();
}
};