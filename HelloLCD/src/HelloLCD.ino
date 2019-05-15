/*
 * Project HelloLCD
 * Description:
 * Author:
 * Date:
 */

#include "LCD.h"

#define MAGIC_NUMBER 1

// Initialize the LCD library - will write to pin TX
LCD lcd = LCD();
String text = "World";
double setpoint = 60.0;

int setText(String newText);
int setSetpoint(String newSetpoint);

struct SavedState {
  double setpoint;
  int magic_number;
};

// setup() runs once, when the device is first turned on.
void setup() {
  Serial.println("Starting up");
  lcd.clear();
  lcd.line2(Time.timeStr());
  lcd.line1("Starting up...");

  initializeValues();

  Particle.variable("text", text);
  Particle.function("text", setText);

  Particle.variable("setpoint", setpoint);
  Particle.function("setpoint", setSetpoint);

  delay(3000);
  lcd.clear();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  String setpointString = String::format("%.1fF", setpoint);
  lcd.line1("Setpoint: " + setpointString);
  lcd.line2(text);
  delay(500);  
}

int setText(String newText) {
  text = newText;
  return 1;
}

int setSetpoint(String newSetpoint) {
  setpoint = newSetpoint.toFloat();
  saveValues();
  return 1;
}

void initializeValues() {
  Serial.println("initializing values");
  SavedState value;
  EEPROM.get(0, value);
  Serial.println(value.magic_number);
  Serial.println(value.setpoint);
  if (value.magic_number == MAGIC_NUMBER) {
    setpoint = value.setpoint;
    Serial.printlnf("using stored setpoint %f", setpoint);
  } else {
    Serial.println("using default value");
    saveValues();
  }
}

void saveValues() {
  Serial.printlnf("Saving setpoint -  %f", setpoint);
  SavedState state = { setpoint,  MAGIC_NUMBER };
  Serial.printlnf("Size: %d", sizeof(state));
  EEPROM.put(0, state);
}
