#pragma once

#include "RPSS.h"

class FingerScanner
{

public:
	FingerScanner(void);
	~FingerScanner(void);
        void FingerScannerBegin();
	char Scan();
        void DB_Check();
};

