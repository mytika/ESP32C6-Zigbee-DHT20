//
//    FILE: DHT20_read_status.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: Demo for DHT20 I2C humidity & temperature sensor
//     URL: https://github.com/RobTillaart/DHT20
//
//  Always check datasheet - front view
//
//          +--------------+
//  VDD ----| 1            |
//  SDA ----| 2    DHT20   |
//  GND ----| 3            |
//  SCL ----| 4            |
//          +--------------+


#include "DHT20.h"
DHT20 DHT;

void setup() {
  Serial.begin(115200);

  Wire.begin();
  DHT.begin();
  delay(1000);
}


void loop() {
  int status = DHT.read();
  // status check and error handling
  float temperature = DHT.getTemperature();
  // float humidity = DHT.getHumidity();
  Serial.print(" | ");
  Serial.println(temperature);
  delay(1000);
}
