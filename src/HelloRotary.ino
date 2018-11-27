/*
 * Project HelloRotary
 * Description:
 * Author:
 * Date:
 */

#include <Encoder.h>

Encoder myEnc(D2, D3);
long oldPosition  = -999;

// setup() runs once, when the device is first turned on.
void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.println("Starting up...");

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }

}
