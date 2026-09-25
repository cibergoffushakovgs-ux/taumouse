#pragma once

#include <inttypes.h>

namespace drivers::motor {
    struct motorParams{
        uint8_t dirPin;
        uint8_t pwmPin;
    };
        class Motor : public motorParams {
        public:
        Motor(motorParams & params) : motorParams(params){}
        void init();
        void set_voltage(float u);

    };

}