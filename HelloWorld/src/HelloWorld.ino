/*
 * Project HelloWorld
 * Description:
 * Author:
 * Date:
 */

int counter = 0;
int led = D7;
int ledState = 0;

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.
  Serial.printlnf("testing %d", ++counter);
  ledState = !ledState;
  digitalWrite(led, (ledState) ? HIGH : LOW);
  delay(1500);
}
