
## Spark Core and Maxim DS18B20 1-Wire Temperature Sensor

There's a lot of libraries out there for the DS18B20.  I wanted one with an API that's easy to use for the common simple scenario of just having the temp sensor be the only device on the 1-wire bus and wanting to read values in fahrenheit.

Sample application using [Spark/Particle Core](http://particle.io) and Maxim [DS18B20 Digital Temperature Sensor](https://www.sparkfun.com/products/245). The **OneWire** source code is taken from [this link](http://pastebin.com/iYcDkrLw) by [@tidwelltimj](https://community.spark.io/users/tidwelltimj/activity). Inspiration also from [LukeUSMC](https://github.com/LukeUSMC/ds18b20-photon), but I couldn't get that library to work on my Core.  The sample code publishes a variable named ***temperature*** with temperature value.
   
##### Wiring

Power to 3.3/5V  
GND to GND  
Signal to D0 (with pullup resistor)

The original project is here:
[https://github.com/krvarma/Dallas_DS18B20_SparkCore](https://github.com/krvarma/Dallas_DS18B20_SparkCore)
