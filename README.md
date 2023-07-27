# kitsLequia
Sistemas de monitorización de parámetros del agua para investigación científica de tratamiento de aguas residuales

### Hardware:
Arduino Bluno Nano
Sensor de pH
Sensor de EC
Sensor de presión
Sensor de temperatura
Lector de balanzas digitales
Pantalla OLED

### Software:
Desarrollo individual de cada sensor
Desarrollo APP bluetooth para visualización y manejo de datos

## Estado Actual
###Hardware:
Sensor de pH: Done and tested
Sensor de EC: Done and tested
Sensor de presión: Done and tested
Sensor de temperatura: Done and tested
Lector de balanzas digitales: Still not getting data from Kern Digital Scales
Pantalla OLED: Done and tested

###Software:
All sensors: done
BLE APP: Android app Done and in testing phase
         IOS app not ready

##BLE APP:
1. Select to which kit or kits to connect and connect
2. See data in real time or Calibrate the sensor (send commands and wait for responses)
3. Choose name of the project and time of data gathering (maybe save data every 30 seconds or 5 minutes)
4. Start the project
5. Finish project and export data to .csv format and send it via e-mail
   _The app should not stop the experiment if it is in background task (if the app is minimized)_
