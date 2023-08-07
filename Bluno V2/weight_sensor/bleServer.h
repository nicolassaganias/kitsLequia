#define PAIR "pair"
#define OD "od"


// Function for get data from BLE
String getBleData() {
  String msg = "";
  unsigned long time = millis() + 500;  // maximum wait for 500 ms
  while (time > millis()) {
    if (Serial.available() > 0) {
      msg = Serial.readStringUntil('\n');  // Receive response from Bluno
    }
  }
  msg.trim();
  return msg;
}