#include "temperature.h"
#include "bleServer.h"

String tag = "t:"; // Tag for temparature

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  String revData = getBleData();

  // To identify the appropiate characteristic
  if(revData.indexOf(PAIR) >= 0){
    Serial.println(tag+PAIR);
  }

  // To check the one demand data request or continious data sneding
  else if(revData.indexOf(OD) >= 0 ){
    float data = readTemperature();
    String sendData = tag + (String) data;
    Serial.println(sendData);
  }

}
