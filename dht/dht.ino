// DHT-sensor-library - Version: Latest 
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
 
void setup(){
 dht.begin();
  Serial.begin(9600);
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
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F\n"));
  
  delay(500);
}
