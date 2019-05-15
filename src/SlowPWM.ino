/*
 * Project SlowPWM
 * Description:
 * Author:
 * Date:
 */

#include "PWM.h"

#define LED A4

PWMControl pwmController = PWMControl(LED, 2000);

int setPower(String percent);
int setFrequency(String millis);

// setup() runs once, when the device is first turned on.
void setup() {
  delay(2000);
  Serial.println("Starting up...");
  Particle.function("power", setPower);
  Particle.function("frequency", setFrequency);
  pinMode(LED, OUTPUT);
  pwmController.setDutyCycle(50);
}

unsigned long lastPrint = 0;

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  pwmController.process();
  unsigned long now = millis();
  if (now - lastPrint > 1000) {
    // pwmController.printDebug();
    lastPrint = now;
  }
}

int setPower(String newValue) {
  Serial.printlnf("Set power: %s%%", newValue);
  pwmController.setDutyCycle(newValue.toInt());
  return 1;
}

int setFrequency(String newValue) {
  Serial.printlnf("Set frequency: %s", newValue);
  pwmController.setFrequency(newValue.toInt());
  return 1;
}
