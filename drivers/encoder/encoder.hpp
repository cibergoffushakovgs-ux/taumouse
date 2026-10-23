#pragma once

#include <inttypes.h>

namespace drivers::encoder{
    struct EncoderParams{
        float tick_to_rad;
        uint8_t pin_clk_a;
        uint8_t pin_b;
        int8_t polarity; // 1 - normal, -1 - inverted




    };
    class Encoder : private EncoderParams {
        private:
            int8_t ab_prev;
            volatile int32_t count;
            float phi_rad_;
        public:
        Encoder(EncoderParams & params) : EncoderParams(params),
        phi_rad(phi_rad_)
        {
        };
        const float &phi_rad;
        void init();
        void tick();
        void tick_irq();
        void reset();


    };
}