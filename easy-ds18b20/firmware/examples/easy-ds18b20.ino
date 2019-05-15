// Simple example of reading a value from a single DS18B20 temperature sensor.
//
// You can view the temperature value on the Particle dashboard
// (https://dashboard.particle.io/user/logs) or via the serial monitor.

#include "easy-ds18b20/DS18B20.h"

// The data pin for the 1-wire bus
#define ONEWIRE_PIN D0
#define LED D7
// how often to read the sensor, in seconds
#define READ_INTERVAL 5

// change to false to output value in celsius instead
boolean useFahrenheit = true;
float temperature;

//object initialization
DS18B20 ds18b20 = DS18B20(ONEWIRE_PIN);

//setup runs once when device is powered or rebooted
void setup() {
    Serial.begin(9600);
    Serial.println("Starting up...");

    //define pin as a output to flash LED
    pinMode(LED, OUTPUT);
}

//loop runs over and over while device is powered
void loop() {

    //heartbeat to determine the loop is executing successfully
    flashLED();

    //get temerature data
    if (useFahrenheit) {
        temperature = ds18b20.getFahrenheit();
    }
    else {
        temperature = ds18b20.getCelsius();
    }

    if (ds18b20.crcCheck()) {
      //publish temperature string to the cloud
      String tempString = String::format("%.2f %s", temperature, useFahrenheit ? "F" : "C");
      Particle.publish("temperature", tempString);

      //output same string to the debug serial
      Serial.println(tempString);
    }
    else {
        Serial.println("CRC check failed, temperature value is bad.");
    }

    //wait
    delay(READ_INTERVAL * 1000);
}

void flashLED(){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
}
