#include "Encoder/Encoder.h"
#include "Rotary/Rotary.h"
#include "Particle.h"

#define ROTARY_1 D2
#define ROTARY_2 D3

void initRotary();
void rotate();

// Encoder myEnc(ROTARY_1, ROTARY_2);
Rotary rotary(ROTARY_1, ROTARY_2);

long oldPosition  = 0;
int value = 60;
int value2 = 0;

void setup() {
  delay(2000);
  initRotary();
  Serial.println("Starting up...");
}

void loop() {
    // processEncoder();

}

void initRotary() {
  Serial.println("initializing rotary");
  rotary.init(rotate);
}

// rotate is called anytime the rotary inputs change state.
void rotate() {
//   Serial.println("rotate");
  unsigned char result = rotary.process();
  if (result == DIR_CW) {
    value--;
    Serial.println(value);
  } else if (result == DIR_CCW) {
    value++;
    Serial.println(value);
  }
}

void processEncoder() {
//   long newPosition = myEnc.read()/4;
//   if (newPosition != oldPosition) {
//     if (newPosition < oldPosition) {
//         value++;
//     } else if (newPosition > oldPosition) {
//         value--;
//     }
//     oldPosition = newPosition;
//     value2 = -oldPosition;
//     Serial.printlnf("%d  |  %d  |  %d", value, value2, newPosition);
//   }
}
