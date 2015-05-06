#include "RPSS.h"
#include "RPSS_States.h"

Comm_Driver::Comm_Driver(){
}

Comm_Driver::~Comm_Driver(){
  
}

void Comm_Driver::setMessage(char result){
  message = result;
}

void Comm_Driver::CommBegin(int baud){
  Serial.begin(baud);
}

RPSS_States Comm_Driver::update_State(){
  
  RPSS_States state;
     switch(message){
             case CHECK_DATABASE:
               state = GOT_NEW_PATRON;
               break;
             case REGISTER_PATRON:
               state = NOT_IN_DATABASE;
               break;
             case CHECK_BREATHALYZER:
               state = IN_DATABASE;
               break;
             case MAINTENANCE_MODE:
               state = MAINTENANCE;
               break;
             case RELEASE_PATRON:  
               state = BREATHALYZER_PASS;
               break;
             case BREATHALYZER_TEST_FAIL:
               state = BREATHALYZER_FAIL;
               break;
             case DEFAULT_STATUS:
               state = RPSS_DEFAULT;
               break;
             default: // RPSS_ERROR_STATE
               state = RPSS_ERROR;
               break;
         }
   return state;
}


void Comm_Driver::wait_for_command(){
   while(!Serial.available()); // block until character is received
   message = Serial.read(); 
}

void Comm_Driver::send_result(){
   Serial.print(message);
}
