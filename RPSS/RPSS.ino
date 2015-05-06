/*
Original Author: Justien Young,
Refactor: Stephen Copeand

Justiens original log should be located at: <project_root>JYlog.txt (one folder above this one)




*/
#include "RPSS.h"

// instantiate the RPSS state machine and set the internal state to START
// this will cause it to go into a listening mode -waiting from an update from
// the GUI or the pi manager -- Stephen Copeland

RPSS_State_Machine_Controller controller(START);

void setup()
{
  // setup all the components, such as the comm driver, Breathalyzer, Cabinets, etc
  controller.RPSS_Begin();
}

void loop()
{
  // run the state machine
  controller.handler();	
}
