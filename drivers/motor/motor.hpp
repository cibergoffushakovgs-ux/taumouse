#pragma once

#include <inttypes.h>

namespace drivers::motor {
    struct motorParams{
        uint8_t dirPin;
        uint8_t pwmPin;
        uint8_t polarity;
        float (*get_voltage)();
    };
        class Motor : public motorParams {
        private:
            uint8_t _pwm;
        public:
        const uint8_t &pwm;
        Motor(motorParams & params) : motorParams(params), pwm(_pwm){}
        void init();
        void set_voltage(float u);

    };

}