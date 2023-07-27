/************************************************************
  Water Sensor Calibration

  The output voltage offset of the sensor is 0.5V (norminal).
  However, due to the zero-drifting of the internal circuit, the
  no-load output voltage is not exactly 0.5V. Calibration needs to
  be carried out as follow.

  Calibration: connect the 3 pin wire to the Arduio UNO (VCC, GND and Signal)
  without connecting the sensor to the water pipe and run the program
  for once. Mark down the LOWEST voltage value through the serial
  monitor and revise the "OffSet" value to complete the calibration.

  After the calibration the sensor is ready for measuring!
**************************************************************/

#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//OLED
// Initialize the display
Adafruit_SSD1306 display(128, 32, &Wire, -1);

//Pressure
const int pinPressure = A0;
const float  OffSet = 0.46 ; // calibration factor: 0.586 for 35bar (500psi) // 0.510 for 16 bar (1.6mpa or 30psi)
float V, P;
float calibrationFactor = 1;
//Timing
unsigned long lastLogTime;

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

  delay(2000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Begin");
  display.display();

  delay(2000);
}

void loop() {
  static unsigned long timepoint = millis();

  // Calculate water pressure
  V = analogRead(pinPressure) * 5.00 / 1024;
  P = (((V - OffSet) * 400) / 100) * calibrationFactor; // /100 to convert kPa to bar // calibrationFactor for correction

  if (millis() - timepoint > 1000U) { //time interval: 1s
    timepoint = millis();

    Serial.print("Voltage:");
    Serial.print(V, 2);
    Serial.print("v");
    Serial.print(" Pressure:");
    Serial.print(P, 2);
    Serial.println("bar");
    display.clearDisplay();

    display.setCursor(0, 0);
    display.print("Voltage:");
    display.println(V, 2);
    display.setCursor(0, 10);
    display.print("Pressure:");
    display.print(P, 2);
    display.println("bar");
    display.display();
  }
}
