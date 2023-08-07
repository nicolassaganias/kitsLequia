/*
 * You can send commands in the serial monitor to execute the calibration.
 * Serial Commands:
 *   enterec -> enter the calibration mode
 *   calec -> calibrate with the standard buffer solution, two buffer solutions(1413us/cm and 12.88ms/cm) will be automaticlly recognized
 *   exitec -> save the calibrated parameters and exit from calibration mode
 */

#include "DFRobot_EC.h"
#include <EEPROM.h>

#define EC_PIN A5 // Connect the ec sensor with Bluno A5 pin
float voltage, ecValue, temperature = 25;
DFRobot_EC ec;

void configEC() {
  ec.begin();
}

float getEC() {
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000U)  //time interval: 1s
  {
    timepoint = millis();
    voltage = analogRead(EC_PIN) / 1024.0 * 5000;  // read the voltage
    //temperature = readTemperature();          // read your temperature sensor to execute temperature compensation
    ecValue = ec.readEC(voltage, temperature);  // convert voltage to EC with temperature compensation
  }
  ec.calibration(voltage, temperature);  // calibration process by Serail CMD
  return ecValue;
}
