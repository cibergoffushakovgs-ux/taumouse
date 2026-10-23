#include <Arduino.h>

#include "drivers/driver_manager.hpp"
void setup(){
    drivers::init();
    Serial.begin(115200);
};


void p_turn(){
    float v = 1.0;
    float err = drivers::encoder_left.phi_rad - drivers::encoder_right.phi_rad;
    float kp = 1.0;
    float u = kp * err;
    drivers::motor_left.set_voltage(v+u);
    drivers::motor_right.set_voltage(v-u);

}
void loop(){
    drivers::encoder_left.tick();
    drivers::encoder_right.tick();
    p_turn();
    Serial.print(drivers::encoder_left.phi_rad);
    Serial.print(" ");
    Serial.println(drivers::encoder_right.phi_rad);
    
    delay(10);
    }

