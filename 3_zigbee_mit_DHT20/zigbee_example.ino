// Copyright 2024 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @brief This example demonstrates Zigbee temperature sensor.
 *
 * The example demonstrates how to use Zigbee library to create a end device temperature sensor.
 * The temperature sensor is a Zigbee end device, which is controlled by a Zigbee coordinator.
 *
 * Proper Zigbee mode must be selected in Tools->Zigbee mode
 * and also the correct partition scheme must be selected in Tools->Partition Scheme.
 *
 * Please check the README.md for instructions and more detailed description.
 *
 * Created by Jan Procházka (https://github.com/P-R-O-C-H-Y/)
 */

#ifndef ZIGBEE_MODE_ED
#error "Zigbee coordinator mode is not selected in Tools->Zigbee mode"
#endif

#include "Zigbee.h"

#define BUTTON_PIN                  9  //Boot button for C6/H2
#define TEMP_SENSOR_ENDPOINT_NUMBER 10

ZigbeeTempSensor zbTempSensor = ZigbeeTempSensor(TEMP_SENSOR_ENDPOINT_NUMBER);
#include "DHT20.h"
DHT20 DHT;

/************************ Temp sensor *****************************/
static void temp_sensor_value_update(void *arg) {
  for (;;) {
    // Read temperature sensor value
    // float tsens_value = temperatureRead();
    int status = DHT.read();
    // status check and error handling
    float temperature = DHT.getTemperature();
    log_v("Temperature sensor value: %.2f°C", temperature);
    // Update temperature value in Temperature sensor EP
    zbTempSensor.setTemperature(temperature);
    delay(3000);
  }
}

/********************* Arduino functions **************************/
void setup() {

  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  Wire.begin();
  DHT.begin();
  delay(1000);


  zbTempSensor.setManufacturerAndModel("Espressif", "pixelediTempSensor");
  zbTempSensor.setMinMaxValue(0, 80);
  zbTempSensor.setTolerance(1);
  Zigbee.addEndpoint(&zbTempSensor);
  Zigbee.begin();

  xTaskCreate(temp_sensor_value_update, "temp_sensor_update", 2048, NULL, 10, NULL);

  // Set reporting interval for temperature measurement in seconds, must be called after Zigbee.begin()
  // min_interval and max_interval in seconds, delta (temp change in °C)
  // if min = 1 and max = 0, reporting is sent only when temperature changes by delta
  // if min = 0 and max = 10, reporting is sent every 10 seconds or temperature changes by delta
  // if min = 0, max = 10 and delta = 0, reporting is sent every 10 seconds regardless of temperature change
  zbTempSensor.setReporting(1, 0, 1);
}

void loop() {
  // langweilt sich der loop
}