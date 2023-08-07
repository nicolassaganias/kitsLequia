#define PRESSURE_SENSOR_PIN A5 // Connect the pressure sensor with Bluno A5 pin

const float OffSet = 0.483;  // Change this Offset voltage from calibration result

float V, P;

// Function for getting pressure from sensor
float getPressure() {
  V = analogRead(PRESSURE_SENSOR_PIN) * (3.3 / 4095.0);  //Sensor output voltage
  P = (V - OffSet) * 250;                                //Calculate water pressure
  return P;
}
