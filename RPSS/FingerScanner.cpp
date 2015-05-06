#include "RPSS.h"


FingerScanner::FingerScanner(void)
{
}


FingerScanner::~FingerScanner(void)
{
}

void FingerScanner::FingerScannerBegin(){
}

//Check's data base for finger ID
char FingerScanner::Scan()
{
  bool inDB = false;
  // scan finger
  
  // check if user is in database if 
  
  
  
  // finally update the peripheral controller, this will then be sent back to the GUI
  
  if(inDB)
    return USER_IN_DATABASE;
    
  else
    return USER_NOT_IN_DATABASE;
  
}

char FingerScanner::add_patron_to_DB(int cabinetID){
   
   // add patron and their associated cabinetID to the database
   return PATRON_REGISTERED_SUCCESSFULLY; 
}
