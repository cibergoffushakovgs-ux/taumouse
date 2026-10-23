#include "encoder.hpp"
#include <Arduino.h>

namespace drivers::encoder {

    const int8_t transitionTable[4][4] = {
    { 0,  1, -1,  0},
    {-1,  0,  0,  1},
    { 1,  0,  0, -1},
    { 0, -1,  1,  0}
    };

    void Encoder::init() {
        pinMode(pin_clk_a, INPUT);
        pinMode(pin_b, INPUT);
        ab_prev = (digitalRead(pin_clk_a) << 1) | digitalRead(pin_b);
        count = 0;
        phi_rad_ = 0.0;
    }

    void Encoder::tick() {

        phi_rad_ = count * tick_to_rad;
    }

    void Encoder::tick_irq() {
        int8_t clk_a = digitalRead(pin_clk_a);
        int8_t b = digitalRead(pin_b);
        int8_t a = clk_a ^ b;
        int8_t ab = (a << 1) | b;
        count += transitionTable[ab_prev][ab] * polarity;
        ab_prev = ab;        
    }
    void Encoder::reset() {
        count = 0;
        phi_rad_ = 0.0;
    }
}