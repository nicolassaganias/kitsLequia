/*
 * You can send commands in the serial monitor to execute the calibration.
 * Serial Commands:
 *   enterph -> enter the calibration mode
 *   calph   -> calibrate with the standard buffer solution, two buffer solutions(4.0 and 7.0) will be automaticlly recognized
 *   exitph  -> save the calibrated parameters and exit from calibration mode
 */

#include "DFRobot_PH.h"
#include <EEPROM.h>

#define PH_PIN A5 // Connect the ph sensor with Bluno A5 Analog pin
float voltage, phValue, temperature = 25;
DFRobot_PH ph;

void configPH() {
  ph.begin();
}

float getPH() {
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000U) {  //time interval: 1s
    timepoint = millis();
    //temperature = readTemperature();         // read your temperature sensor to execute temperature compensation
    voltage = analogRead(PH_PIN) / 1024.0 * 5000;  // read the voltage
    phValue = ph.readPH(voltage, temperature);     // convert voltage to pH with temperature compensation
  }
  ph.calibration(voltage, temperature);  // calibration process by Serail CMD
  return phValue;
}
