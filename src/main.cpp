#include <Arduino.h>
#include "DHT.h"
#include "ACS712.h"
DHT dht;


ACS712 sensor(ACS712_30A, A0);
void setup() {
  // put your setup code here, to run once:
 

  Serial.begin(9600);
  dht.setup(7);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Calibrating... Ensure that no current flows through the sensor at this moment");
  int zero = sensor.calibrate();
  Serial.println("Done!");
  Serial.println("Zero point for this sensor = " + zero);

    float I = sensor.getCurrentDC();
  
  // Send it to serial
  Serial.println(String("I = ") + I + " A");
  

    float h = dht.getHumidity();
  // Read temperature as Celsius
   float t = dht.getTemperature();
  
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  delay(1000);
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" °C\n");
  delay(1000);
}