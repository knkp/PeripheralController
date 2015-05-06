/**
Author: Stephen Copeland

This is a refernece for the possible state's and the communication protocol for the RPSS system.
4/30/2015
*/

#pragma once

typedef enum {
        START,  // this is unique to the peripheral controller - it is used to put the P.C. in a waiting state
	GOT_NEW_PATRON,
	IN_DATABASE,
	NOT_IN_DATABASE,
	REGISTER,           
	BREATHALYZER_PASS,
	BREATHALYZER_FAIL,
	OUTRO,
	RPSS_DEFAULT,  // must be renamed, causes conflicts with Arduino.h include
	MAINTENANCE,
	RPSS_ERROR     // must be renamed, causes conflicts with Arduino.h include
}RPSS_States;

