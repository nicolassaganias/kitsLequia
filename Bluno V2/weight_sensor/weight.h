#include <SoftwareSerial.h>  // Required Library

#define rxPinRS232 9  // Connect the rx pin of RS232 with Bluno Diigtal 9 pin
#define txPinRS232 10 // Connect the tx pin of RS232 with Bluno Diigtal 10 pin

SoftwareSerial mySerial(rxPinRS232, txPinRS232); // Create the software serial object

// Function for configure RS232
void configRS232() {
  mySerial.begin(9600); // Initialize the software serial
}

// Function for getting weight from Serial 
String getWeight() {
  if (mySerial.available()) {
    String data = mySerial.readString(); // Read the incoming string from the software serial
    Serial.println(data); // Print the received string to the hardware serial
    return data;
  }
  return "";
}


