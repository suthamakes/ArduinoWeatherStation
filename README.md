# MiniWeatherStation
> Mini Weather Station is an example of a Personal Weather System (PWS). A personal weather station (PWS) is a set of weather measuring instruments operated by a private individual, club, association, or business (where obtaining and distributing weather data is not a part of the entity's business operation). Personal weather stations have become more advanced and can include many different sensors to measure weather conditions.
#### This project is based on the Arduino Microcontroller for reading the sensors and ESP8266 Module for communications.
The hardware used in this project are:
+ Arduino Microcontroller
+ DHT11 (or DHT22) Temperature Humidity Sensor
+ BMP180 Barometric Sensor
+ Sharp Optical Dust Sensor 
+ Light Dependent Resistor (LDR)
---
### DHT Library
The DHT11 sensor is used for temperature and humidity readings. It uses Adafruit Unified Sensor library which contains DHT.h. It is one of the easy to use libraries and has buitin functions to get and compute values. Methods such as readHumidity() and readTemperature() is used in a DHT object, here 'dht.readHumidity()'. Heat index can also be computed from the DHT library. Adafruit Unified Sensor Library needs to be installed seperately using the built-in library manager in Arduino IDE.

There is a possibility of getting NaN as sensor reading which stands for Not a Number. This is because the Arduino is not getting the value from sensor. The most likely cause of this problem is due to bad hardware connection. So one must check all the wirings and soldering during the connection. Another logical way to tackle this if it persist is to store the previous reading value and whenever it gives NaN reading we can display that previous value.

```js
	//define the program to store backup
		
	t=dht.readTemperature();
		
	if(isnan(t)){
		t=backupT;
		Serial.println(t);
	}
	else{
		Serial.println(t);
	}
```
<br><br>
For details: <sthapa06407@gmail.com>
