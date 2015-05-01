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

RPSS_States Comm_Driver::update_GUI(){
  
  RPSS_States state;
     switch(message){
             
             case CHECK_DATABASE:
               break;
             case REGISTER_PATRON:
               break;
             case USER_NOT_IN_DATABASE:
               break;
             case USER_IN_DATABASE:
               break;
             case CHECK_BREATHALYZER:
               break;
             case BREATHALYZER_TEST_PASS:
               break;
             case BREATHALYZER_TEST_FAIL:
               break;
             case MAINTENANCE_MODE:
               break;
             case PATRON_REGISTERED_SUCCESSFULLY:
               break;
             case RELEASE_PATRON:
               break;
             case RPSS_RELEASED:
               break;
             case TAXI_DEPLOYED:
               break;
             case DEFAULT_STATUS:
               break;
             case DEFAULT_ACK:
               break;
             default: // RPSS_ERROR_STATE
               break;
         }
   return state;
}

void Comm_Driver::wait_for_command(){
   while(!Serial.available()); // block until character is received
   message = Serial.read(); 
}

void Comm_Driver::send_result(char response){
   Serial.print(response);
}
