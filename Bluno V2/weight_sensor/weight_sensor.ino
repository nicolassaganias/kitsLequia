#include "weight.h"
#include "bleServer.h"

String tag = "w:"; // Tag for weight

void setup() {
  Serial.begin(115200);
  configRS232();
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
    String data = getWeight();
    String sendData = tag + data;
    Serial.println(sendData);
  }  
}
