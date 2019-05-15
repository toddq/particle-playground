/*
 * Rotary encoder library for Arduino.
 */

#ifndef rotary_h
#define rotary_h

#include "Particle.h"

// Enable this to emit codes twice per step.
//#define HALF_STEP

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Anti-clockwise step.
#define DIR_CCW 0x20

class Rotary
{
  public:
    Rotary(pin_t, pin_t);
    void init(raw_interrupt_handler_t);
    // Process pin(s)
    unsigned char process();
  private:
    unsigned char state;
    pin_t pin1;
    pin_t pin2;
};

#endif
 