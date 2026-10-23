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


encoder::EncoderParams encoder_left_params = {
    .tick_to_rad = 3.1415926 * 2 / 1430,
    .pin_clk_a = 2,
    .pin_b = 4,
    .polarity = -1};

encoder::EncoderParams encoder_right_params = {
    .tick_to_rad = 3.1415926 * 2 / 1430,
    .pin_clk_a = 3,
    .pin_b = 5,
    .polarity = 1};


motor::Motor motor_left(motor_left_params);
motor::Motor motor_right(motor_right_params);
encoder::Encoder encoder_left(encoder_left_params);
encoder::Encoder encoder_right(encoder_right_params);

void encoder_left_tick_irq() {
    encoder_left.tick_irq();
}
void encoder_right_tick_irq() {
    encoder_right.tick_irq();
}


void init(){
    motor_left.init();
    motor_right.init();
    encoder_left.init();
    encoder_right.init();

    attachInterrupt(digitalPinToInterrupt(encoder_left_params.pin_clk_a), encoder_left_tick_irq, CHANGE);
    attachInterrupt(digitalPinToInterrupt(encoder_right_params.pin_clk_a), encoder_right_tick_irq, CHANGE);
}
};