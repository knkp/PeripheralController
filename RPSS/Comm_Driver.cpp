#include "RPSS.h"
#include "RPSS_States.h"

Comm_Driver::Comm_Driver(){
}

Comm_Driver::~Comm_Driver(){
  
}

void Comm_Driver::setMessage(char result){
  #ifdef DEBUG_ON_COMPUTER
  Serial.println("Entered setMessage function, the message is being set to "+ result);
  #endif
  message = result;
}

void Comm_Driver::CommBegin(int baud){
  Serial.begin(baud);
}

RPSS_States Comm_Driver::update_State(){
#ifdef DEBUG_ON_COMPUTER
Serial.print(message);
#endif
  RPSS_States state;
     switch(message){
             case CHECK_DATABASE:
               #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered CHECK_DATABASE state");
               #endif
               state = GOT_NEW_PATRON;
               break;
             case REGISTER_PATRON:
             #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered REGISTER_PATRON state");
               #endif
               state = NOT_IN_DATABASE;
               break;
             case CHECK_BREATHALYZER:
             #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered CHECK_BREATHALYZER state");
               #endif
               state = IN_DATABASE;
               break;
             case MAINTENANCE_MODE:
             #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered MAINTENENACE_MODE state");
               #endif
               state = MAINTENANCE;
               break;
             case RELEASE_PATRON:  
             #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered RELEASE_PATRON state");
               #endif
               state = BREATHALYZER_PASS;
               break;
             case BREATHALYZER_TEST_FAIL:
               #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered BREATHALYZER_TEST_FAIL state");
               #endif
               state = BREATHALYZER_FAIL;
               break;
             case DEFAULT_STATUS:
               #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered DEFAULT_STATUS state");
               #endif
               state = RPSS_DEFAULT;
               break;
             default: // RPSS_ERROR_STATE
               #ifdef DEBUG_ON_COMPUTER
               Serial.println("Entered ERROR state");
               #endif
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
