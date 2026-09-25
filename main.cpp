#include <Arduino.h>

#include "drivers/driver_manager.hpp"
void setup(){
    drivers::init();
    Serial.begin(115200);
};
void loop(){

    for (int x = 0; x < 50; x++){
    drivers::motor_left.set_voltage(x / 10);
    drivers::motor_right.set_voltage(x / 10);
    Serial.println(drivers::battery_driver.get_volts());
    delay(10);
    }
    for (int x = 0; x < 50; x++){
    drivers::motor_left.set_voltage(-x / 10);
    drivers::motor_right.set_voltage(-x / 10);
    Serial.println(drivers::battery_driver.get_volts());
    delay(10);
    }

}