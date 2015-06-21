#include "RPSS.h"
#define NUMBER_OF_CABINETS 2

#define CABINET_PIN_1   4
#define CABINET_PIN_2   5

Cabinet::Cabinet(void)
{
}

Cabinet::~Cabinet(void)
{
}

void Cabinet::CabinetBegin(void)
{
 CabinetID = 0; 
}
char Cabinet::openPatronCabinet(){
    // perform necessary operation to open the correct cabinet
   
   return RPSS_RELEASED; 
}

int Cabinet::get_new_cabinet(){
  // find the next available cabinet and open it for the patron, also return the cabinets id so it can be associated
  // with the patron in the database
  CabinetID++;
  CabinetID = (CabinetID % NUMBER_OF_CABINETS);
  return CabinetID;
}
