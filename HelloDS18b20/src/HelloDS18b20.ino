/*
 * Project HelloDS18b20
 * Description: Hello World app for reading temperature
 * Author:
 * Date:
 */

#include "TempSensor.h"

#define SENSOR_PIN D0

// setup() runs once, when the device is first turned on.
void setup() {
  Serial.begin(9600);
  initSensor(SENSOR_PIN);
  delay(5000);
  Serial.println("Starting up...");
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  Serial.printf("Temperature %.2f F ", getTemp());
  Serial.println();
  delay(3000);
}
