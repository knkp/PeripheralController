#pragma once
#include "RPSS.h"

class Wind
{

        int threshold; // set this during calibration, use it to verify patron is breathing  

public:
	Wind(void);
	~Wind(void);
        void wind_calibrate();
        void waitForBreath();
};

