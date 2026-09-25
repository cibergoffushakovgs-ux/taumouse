#pragma once
#include "motor/motor.hpp"


namespace drivers{
    extern motor::Motor motor_left, motor_right;
    void init();
};
