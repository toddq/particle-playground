#ifndef PWM_CONTROL
#define PWM_CONTROL

#include "Particle.h"

// low and slow pwm
class PWMControl {
  public:
    PWMControl(pin_t pin, unsigned long frequency = 1000);
    void process();
    void setDutyCycle(int percent);
    void setFrequency(long frequency);
    void printDebug();

  private:
    pin_t _outputPin;
    // could also be named cycleTime
    unsigned long _frequency;
    unsigned long _dutyCycle;

    unsigned long _cycleStart;
    bool _powerState;

    void power(bool newState);
};

#endif
