#include "RPSS.h"
#include "FingerPrint_Library.h"
#include "SoftwareSerial.h"

uint8_t getFingerprintEnroll(uint8_t id);

int solenoidControl = 5; // Digital Arduino Pin to control solenoid

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

Cabinet::Cabinet(void)
{
}

Cabinet::~Cabinet(void)
{
}
   
  
char Cabinet::openPatronCabinet(){
  // perform necessary operation to open the correct cabinet
  // found a match!
  digitalWrite(solenoidControl, LOW);
  delay(10000);
  digitalWrite(solenoidControl, HIGH);
  //Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  //Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
 return RPSS_RELEASED; 
}


int Cabinet::get_new_cabinet()
{
  // find the next available cabinet and open it for the patron, also return the cabinets id so it can be associated
  // with the patron in the database
  if ()
{
  // action A
}
else
{
  // action B
}
  int cabinetID;
}
