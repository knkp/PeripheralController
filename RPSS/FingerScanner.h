#pragma once

#include "RPSS.h"

class FingerScanner
{

public:
	FingerScanner(void);
	~FingerScanner(void);
        void FingerScannerBegin();
	char Scan();
        char add_patron_to_DB(int);
};
