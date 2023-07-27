# kitsLequia
Water monitoring systems for scientific research on wastewater treatment

### Hardware:
Arduino Bluno Nano
pH sensor
EC sensor
Pressure sensor
Temperature sensor
Digital scale reader
OLED Display

### Software:
Individual development of each sensor
Development of bluetooth APP for visualisation and data management

## Current status
###Hardware:
pH sensor: Done and tested
EC sensor: Done and tested
Pressure sensor: Done and tested
Temperature sensor: Done and tested
Digital scale reader: Still not getting data from Kern Digital Scales
OLED display: Done and tested

###Software:
All sensors: Done
BLE APP: Android app Done and in testing phase
         IOS app not ready

##BLE APP:
1. Select to which kit or kits to connect and connect
2. See data in real time or Calibrate the sensor (send commands and wait for responses)
3. Choose name of the project and time of data gathering (maybe save data every 30 seconds or 5 minutes)
4. Start the project
5. Finish project and export data to .csv format and send it via e-mail
   _The app should not stop the experiment if it is in background task (if the app is minimized)_
