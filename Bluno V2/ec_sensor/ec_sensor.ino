#include "ec.h"
#include "bleServer.h"

String tag = "ec:"; // Tag for ec sensor

void setup() {
  Serial.begin(115200);
  configEC();
  delay(1000);
}

void loop() {
  String revData = getBleData();

  // To identify the appropiate characteristic
  if(revData.indexOf(PAIR) >= 0){
    Serial.println(tag+PAIR);
  }

  // To check the one demand data request or continious data sneding
  else if(revData.indexOf(OD) >= 0){
    float data = getEC();
    String sendData = tag + (String) data;
    Serial.println(sendData);
  }  
}
