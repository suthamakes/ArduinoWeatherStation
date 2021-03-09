#include <DHT.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include<ESP8266WiFi.h>
#include "config.h"

#define ALTITUDE 1322

#define DHTPIN                    D5
#define DHTTYPE                   DHT11
DHT dht(DHTPIN, DHTTYPE);
SFE_BMP180 pressure;

AdafruitIO_Feed *centi = io.feed("centi");
AdafruitIO_Feed *faren = io.feed("faren");
AdafruitIO_Feed *humid = io.feed("humid");
AdafruitIO_Feed *pres = io.feed("pres");

void setup() {
  
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASS);
  io.connect();
  io.run();
  dht.begin();
  pressure.begin();
}

void th(){
  float c = dht.readTemperature();
  delay(150);
  float f = dht.readTemperature(true);
  delay(150);
  float h = dht.readHumidity();
  delay(150);
  centi->save(c);
  faren->save(f);
  humid->save(h);
  Serial.print(c);
  Serial.print("   ");
  Serial.print(f);
  Serial.print("   ");
  Serial.println(h);
}

void bmp(){
char status;
  double T,P,p0,a;
  
  // If you want to measure altitude, and not pressure, you will instead need
  // to provide a known baseline pressure. This is shown at the end of the sketch.

  // You must first get a temperature measurement to perform a pressure reading.
  
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.

  status = pressure.startTemperature();
    // Wait for the measurement to complete:
    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
      // Print out the measurement:
//      Serial.print("temperature: ");
//      Serial.print(T,2);
//      Serial.print(" deg C, ");
//      Serial.print((9.0/5.0)*T+32.0,2);
//      Serial.println(" deg F");
      
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.

      status = pressure.startPressure(3);
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
          // Print out the measurement:
//          Serial.print("absolute pressure: ");
//          Serial.print(P,2);
//          Serial.print(" mb, ");
//          Serial.print(P*0.0295333727,2);
//          Serial.println(" inHg");

          // The pressure sensor returns abolute pressure, which varies with altitude.
          // To remove the effects of altitude, use the sealevel function and your current altitude.
          // This number is commonly used in weather reports.
          // Parameters: P = absolute pressure in mb, ALTITUDE = current altitude in m.
          // Result: p0 = sea-level compensated pressure in mb

          p0 = pressure.sealevel(P,ALTITUDE); // we're at 1655 meters (Boulder, CO)
          Serial.print("relative (sea-level) pressure: ");
          Serial.print(p0,2);
          Serial.print(" mb, ");
          Serial.print(p0*0.0295333727,2);
          Serial.println(" inHg");
        pres->save(p0);
}
void loop() {
  th();
  bmp();
  delay(5000);
  
  delay(5000);

}
