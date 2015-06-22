#pragma once

#include "RPSS.h"


class Cabinet
{
  char CabinetID;
public:
	Cabinet(void);
	~Cabinet(void);

        void CabinetBegin(void);
        char openPatronCabinet(int);
        char closePatronCabinet(int);

};

