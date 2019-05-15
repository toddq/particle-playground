/*
 * Project WiFiConfigure
 * Description:
 * Author:
 * Date:
 */

#include "softap_pages.h"
#include "LCD.h"
#include "clickButton.h"

#define BUTTON D4

// STARTUP(softap_set_application_page_handler(handleCustomPage, nullptr));

// SYSTEM_MODE(SEMI_AUTOMATIC);

unsigned long lastActivity;
const long loopTime = 5000;
const int LONG_PRESS = -1;

bool hasWifi = false;
bool isListening = false;

LCD lcd = LCD();
ClickButton _button(BUTTON);

void setup() {
  delay(2000);
  lcd.clear();
  lcd.line2(Time.timeStr());
  lcd.line1("Starting up...");
  delay(3000);
}

// will the loop continue to run if there's no wifi? (it shouldn't be required)
// will Particle.process be called automaticly?

void loop() {
  processButton();
  if (millis() - lastActivity > loopTime) {
    Serial.println(Time.timeStr());
    lcd.line1(WiFi.SSID());
    lcd.line2(String::format("%d", millis()));
    lastActivity = millis();
  }
}

void processButton() {
  _button.Update();

  // can restart or not
  static const bool restartAfterWifiChange = false;

  if (isListening) {
    Serial.println("Hmmm, isListening in loop");
    isListening = false;
    lcd.clear();
    lcd.line1("New WiFi set");

    if (restartAfterWifiChange) {
      Serial.println("Restarting...");
      lcd.line2("Restarting...");
      delay(2000);
      System.reset();
    } else {
      delay(2000);
    }
    return;
  }

  if (_button.clicks == LONG_PRESS) {
    Serial.println("BUTTON LONG PRESS");
    enterWifiSetupMode();
  }
}

// seems like once we go into listening mode, might be best to require a device reset afterwards
void enterWifiSetupMode() {
  if (isListening) {
    Serial.println("How'd I get here?");
    Serial.println("Device is already listening.");
    Serial.println("TODO: initiate reset()");
    dumpWifi();
    return;
  }
  String apPrefix = "Photon";
  String apName = apPrefix + "-xxx";
  System.set(SYSTEM_CONFIG_SOFTAP_PREFIX, apPrefix);
  Serial.println("Access Point: " + apName);
  lcd.clear();
  lcd.line1("WiFi: " + apName);
  lcd.line2("     192.168.0.1");
  isListening = true;
  WiFi.listen();
  Serial.println("After wifi.listen, now what?");
}

void dumpWifi() {
  Serial.print("Current ssid: ");
  Serial.println(WiFi.SSID());
  Serial.print("Getting stored credential list...    ");
  WiFiAccessPoint ap[10];
  int found = WiFi.getCredentials(ap, 10);
  Serial.printlnf("found %d", found);
  for (int i=0; i<found; i++) {
    // Serial.println("");
    Serial.print("ssid: ");
    Serial.println(ap[i].ssid);
    // Serial.println(ap[i].security);
    // Serial.println(ap[i].channel);
    // Serial.println(ap[i].rssi);
  }
}

// SYSTEM_MODE(SEMI_AUTOMATIC);
void connectOrListenOnStartup() {
  Serial.println("Setup");
  Serial.println("Trying to connect to known networks");
  WiFi.on();
  WiFi.connect();
  if(waitFor(WiFi.ready, 15000)) {
    Serial.println("Wifi connected.  Connecting to Particle cloud");
    hasWifi = true;
    // Connect to Particle Cloud
    Particle.connect();
  } else {
    // No known wifi found.  go into listening mode
    Serial.println("No known wifi found.  Entering listen mode");
    WiFi.disconnect();
    isListening = true;
    // newWiFi = true;                 // Set flag to say we are listening for new WiFi credentials.
    WiFi.listen();

    // so listen mode WILL BLOCK application code unless system multithreading is enabled
    // I don't think I want to go down the road of messing with system thread, so I think I like the idea better
    // of only going into listening mode based on user interaction

  }
}
