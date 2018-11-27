#include "ClickButton/ClickButton.h"
#include "Encoder/Encoder.h"
#include "Rotary/Rotary.h"
#include "RotaryEncoder/RotaryEncoder.h"
#include "Particle.h"

#define ROTARY_1 D2
#define ROTARY_2 D3
#define ROTARY_BUTTON D4
#define LED D7

#define SHORT_PRESS 1
#define LONG_PRESS -1

void initRotary();
void rotate();
void initRotaryEncoder();
void rotate2();
void rotate3();
void dumpWifi();
void processRotaryButton();

// Encoder myEnc(ROTARY_1, ROTARY_2);
// Rotary rotary(ROTARY_1, ROTARY_2);
RotaryEncoder rotary(ROTARY_1, ROTARY_2);

ClickButton rotaryButton(ROTARY_BUTTON);

long oldPosition  = 0;
int value = 60;
int value2 = 0;
int buttonState = 0;
bool settingsMode = false;

void setup() {
  delay(2000);
//   initRotary();
  initRotaryEncoder();
  pinMode(LED, OUTPUT);
  pinMode(ROTARY_BUTTON, INPUT_PULLUP);
  
  Serial.println("Starting up...");
  // dumpWifi();
}

void loop() {
    // processEncoder();
    processRotaryButton();
    // delay(5);
}

void processRotaryButton() {
  rotaryButton.Update();
  if (rotaryButton.clicks == SHORT_PRESS) {
    if (settingsMode) {
      Serial.println("exit settings mode");
      settingsMode = false;
    }
  } else if (rotaryButton.clicks == LONG_PRESS) {
    // setEditMode(true);
    if (!settingsMode) {
      Serial.println("enter settings mode");
      settingsMode = true;
    }
  }
}

// void processRotaryButton() {
//   int newButtonState = digitalRead(ROTARY_BUTTON);
//   if (newButtonState != buttonState) {
//     buttonState = newButtonState;
//     digitalWrite(LED, !buttonState);
//     Serial.printlnf("button: %d", buttonState);
//   }
// }

void dumpWifi() {
  Serial.print("Current ssid: ");
  Serial.println(WiFi.SSID());
  Serial.print("Getting stored credential list...    ");
  WiFiAccessPoint ap[10];
  int found = WiFi.getCredentials(ap, 10);
  Serial.printlnf("found %d", found);
  for (int i=0; i<found; i++) {
    Serial.println("");
    Serial.print("ssid: ");
    Serial.println(ap[i].ssid);
    Serial.println(ap[i].security);
    Serial.println(ap[i].channel);
    Serial.println(ap[i].rssi);
  }
}

void initRotary() {
  // Serial.println("initializing rotary");
  // rotary.init(rotate);
}

void initRotaryEncoder() {
    Serial.println("initializing rotary encoder");
    // rotary.init(rotate2);
    rotary.init(rotate3);
}

void rotate2() {
  // Serial.println("rotate2");
  // int newPosition = rotary.process();
  // if (newPosition != oldPosition) {
  //   if (newPosition > oldPosition) {
  //       value++;
  //   } else if (newPosition < oldPosition) {
  //       value--;
  //   }
  //   oldPosition = newPosition;
  //   value2 = -oldPosition;
  //   Serial.printlnf("%d  |  %d  |  %d", value, value2, newPosition);
  // }
}

void rotate3() {
  int rotation = rotary.process();
  if (rotation == 0) {
    return;
  }

  if (settingsMode) {
    value2 += rotation;
    Serial.printlnf("Alt: %d", value2);
  } else {
    value += rotation;
    Serial.printlnf("Val: %d", value);
  }
  // value += rotary.process();
  // // Serial.printf("\r%d    ", value);
  // Serial.println(value);
}

// rotate is called anytime the rotary inputs change state.
void rotate() {
//   Serial.println("rotate");
  // unsigned char result = rotary.process();
  // if (result == DIR_CW) {
  //   value--;
  //   Serial.println(value);
  // } else if (result == DIR_CCW) {
  //   value++;
  //   Serial.println(value);
  // }
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
