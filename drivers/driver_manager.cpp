#include "driver_manager.hpp"

namespace drivers
{
motor::motorParams motor_left_params = {
    .dirPin = 7,
    .pwmPin = 9};

motor::motorParams motor_right_params = {
    .dirPin = 8,
    .pwmPin = 10};

motor::Motor motor_left(motor_left_params);
motor::Motor motor_right(motor_right_params);

void init(){
    motor_left.init();
    motor_right.init();
}
};