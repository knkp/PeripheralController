#pragma once1

#include "Adafruit_Fingerprint.h"


#include "RPSS.h"

//#include "C:\Program Files (x86)\Arduino\libraries\Adafruit_Fingerprint\Adafruit_Fingerprint.h"

class FingerScanner
{
  //Adafruit_Fingerprint finger;

public:
	FingerScanner(void);
	~FingerScanner(void);
        void FingerScannerBegin();
	char Scan();
        char add_patron_to_DB(int);
};

