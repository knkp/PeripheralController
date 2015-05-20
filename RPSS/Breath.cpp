#include "RPSS.h"



Breath::Breath(void)
{
}


Breath::~Breath(void)
{
}
void Breath::breath_calibrate(){
   // set the threshold to the correct value 
  
}

char Breath::check_patron_BAC(){
     bool pass;
    
    
     // accumulate enough data from the sensor to perform a BAC check
    
     // determine if they have passed or failed and pass the results up the machine
    
    if(pass)
       return BREATHALYZER_TEST_PASS;
    else
       return BREATHALYZER_TEST_FAIL;
}
