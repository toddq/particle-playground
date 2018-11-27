#include "Encoder/Encoder.h"
#include "Rotary/Rotary.h"
#include "RotaryEncoder/RotaryEncoder.h"
#include "Particle.h"

#define ROTARY_1 D2
#define ROTARY_2 D3
#define ROTARY_BUTTON D4
#define LED D7

void initRotary();
void rotate();
void initRotaryEncoder();
void rotate2();
void rotate3();
void dumpWifi();

// Encoder myEnc(ROTARY_1, ROTARY_2);
// Rotary rotary(ROTARY_1, ROTARY_2);
RotaryEncoder rotary(ROTARY_1, ROTARY_2);

long oldPosition  = 0;
int value = 60;
int value2 = 0;

void setup() {
  delay(2000);
//   initRotary();
  initRotaryEncoder();
  pinMode(LED, OUTPUT);
  Serial.println("Starting up...");
  // dumpWifi();
}

void loop() {
    // processEncoder();
}

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
  value += rotary.process();
  Serial.printf("\r%d    ", value);
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
