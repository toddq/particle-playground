
Spark Core and Dallas DS18B20 Temperature Sensor with Published events and IFTTT
------------------------------------------------


I forked this project to implement publishing an event and outputting the variables as a double so that I could attach an IFTTT module that would send a text when the temperature reached a threshold.

Sample application using Spark Core and Dallas [DS18B20 Digital Temperature Sensor][1]. The **OneWire** source code is taken from [this link][2] by [@tidwelltimj][3]. I just separated this into two classes *OneWire* and *DS18B20*. The sample code publish a variable named ***tmpinfo*** with temperature value.

**Wiring**
Power to 3.3/5V
GND to GND
Signal to D2 (with pullup resistor)

DS18b20: https://www.sparkfun.com/products/245
SparkCore: http://spark.io


The original project is here:
https://github.com/krvarma/Dallas_DS18B20_SparkCore
