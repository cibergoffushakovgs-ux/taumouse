#include "motor.hpp"
#include <Arduino.h>

namespace drivers::motor {
    void Motor::init() {
        pinMode(dirPin, OUTPUT);
        pinMode(pwmPin, OUTPUT);
    }

    void Motor::set_voltage(float u){
        digitalWrite(dirPin, (u > 0)^polarity);
        _pwm = constrain(fabs(u) / get_voltage() * 255, 0, 255);
        analogWrite(pwmPin, _pwm);
    }

}