// Adafruit_Sensor - Version: Latest 
#include <Adafruit_Sensor.h>

// DHT-sensor-library - Version: Latest 
#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
 
void setup(){
 dht.begin();
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n");
  delay(1000);//Wait before accessing Sensor
 
}
 
void loop(){
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

//try catch block needed  
//to test if sensor is running and giving out value
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  
  delay(500);
}
