#include "RPSS.h"
#ifndef DEBUG
#endif


#define POSSIBLE_PATRON_AMOUNT 5  // this is how many patrons are allowed to be in the system (related to how many cabinets total in array)

#define DEBUGGINGSHIT

uint8_t getFingerprintEnroll(uint8_t id);
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


FingerScanner::FingerScanner(void)
{
// finger = Adafruit_Fingerprint(mySerial);
}


FingerScanner::~FingerScanner(void)
{
}

void FingerScanner::FingerScannerBegin(){
  uint8_t p = -1;

#ifdef DEBUGGINGSHIT
  Serial.println("WE MADE IT TO THE FINGER SCANNER BEGIN STATEMENT HOOOOORRRRRRRYYYYYY SHEEEET!");
#endif
        
  finger.begin(57600);
 if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  int leftOverFingers = 0;
  for(leftOverFingers = 0; leftOverFingers < POSSIBLE_PATRON_AMOUNT; leftOverFingers++)
  {
#ifdef DEBUGGINGSHIT
  Serial.println("CAN HAZ EMPTY DATABAZZZEE!?");
#endif
    finger.deleteModel(leftOverFingers); // being sloppy, code is simple enought though that it's not hard to track down which state we're in during failures -- SC
  }
  
#ifdef DEBUGGINGSHIT
  Serial.println("we got past the finger scanner begin statement.... motherfucker");
#endif
}

//Check's data base for finger ID
char FingerScanner::Scan()
{

  bool inDB = false;
  uint8_t p;
  
  #ifndef DEBUG

  #endif
  
  p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      return USER_IN_DATABASE;
      break;
    case FINGERPRINT_NOFINGER:
      return USER_NOT_IN_DATABASE;
    default:
      //Serial.println("Unknown error");
      break;
    }
  return USER_NOT_IN_DATABASE;
  
}

#ifndef DEBUG
/*void loop()                     // run over and over again
{
  //Serial.println("Type in the the name you want to save this finger as...");
  uint8_t id = 0;
  while (true) {
    while (! Serial.available());
    char c = Serial.read();
    if (! isdigit(c)) break;
    id *= 10;
    id += c - '0';
  }
  Serial.print("Enrolling name ");
  //Serial.println(id);
  
  while (!  getFingerprintEnroll(id) );
}*/

uint8_t getFingerprintEnroll(uint8_t id) {
  uint8_t p = -1;
  //Serial.println("Waiting for valid finger to enroll");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      break;
    default:
      //Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }
  
  //Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }

  p = -1;
  //Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      //Serial.println("Imaging error");
      break;
    default:
      //Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      ////Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      ////Serial.println("Image too messy");
      //return p;
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      ////Serial.println("Communication error");
      //return p;
      break;
    case FINGERPRINT_FEATUREFAIL:
      ////Serial.println("Could not find fingerprint features");
      //return p;
      break;
    case FINGERPRINT_INVALIDIMAGE:
      ////Serial.println("Could not find fingerprint features");
      //return p;
      break;
    default:
      ////Serial.println("Unknown error");
      //return p;
  }
  
  
  // OK converted!
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    ////Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    ////Serial.println("Communication error");
    //return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    ////Serial.println("Fingerprints did not match");
    //return p;
  } else {
    ////Serial.println("Unknown error");
    //return p;
  }     
 
  if(inDB)
    return USER_IN_DATABASE;
    
  else
    return USER_NOT_IN_DATABASE;
  
}
#endif

char FingerScanner::add_patron_to_DB(int cabinetID){
   #ifndef DEBUG
   // add patron and their associated cabinetID to the database
   p = finger.storeModel(cabinetID);
  if (p == FINGERPRINT_OK) {
    //Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) { 
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    //Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    //Serial.println("Error writing to flash");
    return p;
  } else {
    //Serial.println("Unknown error");
    return p;
  }
  
  #endif
   return PATRON_REGISTERED_SUCCESSFULLY; 
}
