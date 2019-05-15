#include "Particle.h"
#include "RotaryEncoder.h"

// RotaryEncoder::RotaryEncoder(int _pin1, int _pin2) {
//   RotaryEncoder(_pin1, _pin2, -1);
// }

RotaryEncoder::RotaryEncoder(int _pin1, int _pin2, int _pushPin) {
    pin1 = _pin1;
    pin2 = _pin2;
    pushPin = _pushPin;
    position = 0;
    A_set = true;
    B_set = false;
}

void RotaryEncoder::init(raw_interrupt_handler_t handler) {
  Serial.printlnf("RotaryEncoder::init  %d, %d", pin1, pin2);
  // Set pins to input.
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  if (pushPin >= 0) {
    pinMode(pushPin, INPUT_PULLUP);
  }

  attachInterrupt(pin1, handler, CHANGE);
  attachInterrupt(pin2, handler, CHANGE);
}

int RotaryEncoder::process() {
  // Serial.println("RotaryEncoder::process()");
  // Serial.printlnf("A_set: %d", A_set);
  // Serial.printlnf("B_set: %d", B_set);
  // Serial.printlnf("pin1: %d", digitalRead(pin1));
  // Serial.printlnf("pin2: %d", digitalRead(pin2));

  if( digitalRead(pin1) != A_set ) {  // debounce once more
    // Serial.println("A");
    A_set = !A_set;
    // adjust counter + if A leads B
    if ( A_set && !B_set )
      // position += 1;
      return 1;
  } else if( digitalRead(pin2) != B_set ) {
    // Serial.println("B");
    B_set = !B_set;
    //  adjust counter - 1 if B leads A
    if( B_set && !A_set )
      // position -= 1;
      return -1;
  } else {
    // Serial.println("else");
  }
  // return position;
  return 0;
}
