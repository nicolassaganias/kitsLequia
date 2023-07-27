#include <OneWire.h>
#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DFRobot_PH.h"

//OLED
// Initialize the display
Adafruit_SSD1306 display(128, 32, &Wire, -1);

//Temperature chip i/o
int DS18S20_Pin = 2; //DS18S20 Signal pin on digital 2
OneWire ds(DS18S20_Pin);  // on digital pin 2

//Timing
unsigned long lastLogTime;

//PH
#define PH_PIN A0
float voltage, phValue, temperature = 25;
DFRobot_PH ph;

void setup() {
  Serial.begin(9600);

  // Initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Print a string
  display.setCursor(0, 0);
  display.print("Hello, there!");
  display.display();

  delay(1000);

  ph.begin();

  delay(2000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Begin");
  display.display();

  delay(2000);
}

void loop() {
  static unsigned long timepoint = millis();

  voltage = analogRead(PH_PIN) / 1024.0 * 5000; // read the voltage
  temperature = readTemperature();          // read your temperature sensor to execute temperature compensation
  phValue =  ph.readPH(voltage, temperature); // convert voltage to EC with temperature compensation


  if (millis() - timepoint > 1000U) { //time interval: 1s
    timepoint = millis();
    //    Serial.print("temperature:");
    //    Serial.print(temperature, 1);
    //    Serial.print("^C  EC:");
    //    Serial.print(ecValue, 2);
    //    Serial.println("ms/cm");

    //    display.setCursor(0, 14);
    //    display.println(F("SD"));
    //    display.println(3.141592);
    display.clearDisplay();

    display.setCursor(0, 0);
    display.print("PH:");
    display.println(phValue,2);
    display.display();

    display.setCursor(0, 10);
    display.print("T:");
    display.print(temperature, 2);
    display.println("C");
    display.display();
  }

  ph.calibration(voltage, temperature);         // calibration process by Serail CMD
}

float readTemperature() {
  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
    //no more sensors on chain, reset search
    ds.reset_search();
    return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  byte present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad


  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
}
