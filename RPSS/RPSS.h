#pragma once
/*
  Author: Stephen Copeland
  
  This is just to speed up development, any time we have a new file that needs to be included somewhere, just toss it here, and add the "#include RPSS.h" to 
  the new file - it will find it's reference. This is sloppy, yes, but considering the work that is left, speed and readability are more important.
  
  Future note: if anyone would like to work on cleaning this further after I refactor, please feel free!
  4/30/2015
*/

#include <Arduino.h>
#include  "FingerScanner.h"
#include "Comm_Driver.h"
#include "Breath.h"
#include "Cabinet.h"
#include "RPSS_State_Machine_Controller.h"
#include "RPSS_States.h"
#include "Wind.h"
