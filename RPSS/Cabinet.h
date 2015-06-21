#pragma once

#include "RPSS.h"


class Cabinet
{
  int CabinetID;
public:
	Cabinet(void);
	~Cabinet(void);

        void CabinetBegin(void);
        char openPatronCabinet();
        int get_new_cabinet();

};

