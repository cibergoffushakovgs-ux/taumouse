#include <Arduino.h>

#include "drivers/driver_manager.hpp"

int main(){
    drivers::init();
    drivers::motor_left.set_voltage(9.0f);
    drivers::motor_right.set_voltage(9.0f);
};