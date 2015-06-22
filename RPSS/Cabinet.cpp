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
  pinMode(CABINET_PIN_1, OUTPUT);
  pinMode(CABINET_PIN_2, OUTPUT);
  digitalWrite(CABINET_PIN_1,LOW);
  digitalWrite(CABINET_PIN_2,LOW);
 CabinetID = 0; 
}
char Cabinet::openPatronCabinet(int ID){
    // perform necessary operation to open the correct cabinet
    
    if(ID == 0){
      digitalWrite(CABINET_PIN_1, HIGH); 
    }
    
    else if(ID == 1){
      digitalWrite(CABINET_PIN_2, HIGH); 
    }
   return RPSS_RELEASED; 
}

char Cabinet::closePatronCabinet(int ID){

 if(ID == 0){
      digitalWrite(CABINET_PIN_1, LOW); 
    }
    
    else if(ID == 1){
      digitalWrite(CABINET_PIN_2, LOW); 
    } 
    
    return RPSS_RELEASED;
  
}

/*
int Cabinet::get_new_cabinet(){
  // find the next available cabinet and open it for the patron, also return the cabinets id so it can be associated
  // with the patron in the database
  CabinetID++;
  CabinetID = (CabinetID % NUMBER_OF_CABINETS);
  return CabinetID;
}*/
