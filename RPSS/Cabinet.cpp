#include "RPSS.h"


Cabinet::Cabinet(void)
{
}

Cabinet::~Cabinet(void)
{
}

char Cabinet::openPatronCabinet(){
    // perform necessary operation to open the correct cabinet
   
   return RPSS_RELEASED; 
}

int Cabinet::get_new_cabinet(){
  // find the next available cabinet and open it for the patron, also return the cabinets id so it can be associated
  // with the patron in the database
  int cabinetID;
}
