/*
Author: Stephen Copeland

This is equivalent to the "handler" on the TivaC
it manage's the transitions of the state machine
4/30/2015

*/
#pragma once

#include "RPSS.h"

#include "RPSS_States.h"

class RPSS_State_Machine_Controller{  
  
     RPSS_States currentState;
  
   public:   
     Comm_Driver comm_driver;
     FingerScanner scanner;
   
   // provide the state machine with the state it should start with
     RPSS_State_Machine_Controller(RPSS_States);
     ~RPSS_State_Machine_Controller(void);
     
   // use this to setup members
    void RPSS_Begin();
   // should run forever, handle state machine
    void handler(void);
       
  
};

