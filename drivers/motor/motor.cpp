#include "motor.hpp"
#include <Arduino.h>

namespace drivers::motor {
    void Motor::init() {
        pinMode(dirPin, OUTPUT);
        pinMode(pwmPin, OUTPUT);
    }

    void Motor::set_voltage(float u){
        digitalWrite(dirPin, u > 0);
        uint8_t pwm = constrain(u / 9.0 * 255, 0, 255);
        analogWrite(pwmPin, pwm);
    }

}