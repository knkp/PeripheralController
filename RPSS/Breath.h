#pragma once

#include "RPSS.h"


class Breath
{
       int threshold; // set this during calibration, use it to see if patron is above or below the legal limit

public:
	Breath(void);
	~Breath(void);
        void breath_calibrate();
        char check_patron_BAC();
};

