
//***********************************************************
//USB DEBUG
// find usb: ls -la /dev/tty.usb*
// screen /dev/tty.usbmodem1421  9600




//QUERY VARIABLES
//YOU MUST REPLACE THE {DEVICE_ID} AND THE {ACCESS_TOKEN} IN THE URLS BELOW
//get temp (string) variable
//curl https://api.spark.io/v1/devices/{DEVICE_ID}/temp?access_token={ACCESS_TOKEN}

//get "f" variable
//curl https://api.spark.io/v1/devices/{DEVICE_ID}/f?access_token={ACCESS_TOKEN}


//EVENTS
//notified when debug statement happens
//curl -H "Authorization: Bearer {ACCESS_TOKEN}" https://api.spark.io/v1/events/temperatureInfo




#include "DS18B20.h"
#include "OneWire.h"

//variable definitions
int sensorPin = D2;
int ledPin = D7;
char temperatureInfo[64];
float fahrenheit;
float celsius;
double f;



//object initialization
DS18B20 ds18b20 = DS18B20(sensorPin);





//setup runs once when device is powered or rebooted
void setup() {
    //start serial communication for debugging
    Serial.begin(9600);

    //define pin 7 as a output to flash LED
    pinMode(ledPin, OUTPUT);

    //define public variables
    Spark.variable("temp", temperatureInfo, STRING);
    Spark.variable("f", &f, DOUBLE);
}

//loop runs over and over while device is powered
void loop() {

    //do initial search to find all connected 1-Wire devices on the bus
    if(!ds18b20.search()){
        Serial.println("No more addresses.");
        Serial.println();
        ds18b20.resetsearch();
        delay(250);
        return;
    }

    //get temerature data
    celsius = ds18b20.getTemperature();
    fahrenheit = ds18b20.convertToFahrenheit(celsius);

    //convert data to more useful formats
    f = (double)fahrenheit;
    sprintf(temperatureInfo, "%2.2f", fahrenheit);

    //publish temperature string to any subscribed (listening) devices
    Spark.publish("temperatureInfo", temperatureInfo);

    //output same string to the debug serial
    Serial.println(temperatureInfo);

    //heartbeat to determine the loop is executing successfully
    flashLED();

    //wait 5 seconds
    delay(5000);
}

//heartbeat function
void flashLED(){
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}
