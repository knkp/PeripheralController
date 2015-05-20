#include "RPSS.h"


#define WIND_INPUT A0   // the input from the wind sensor is A0
#define WAIT_TIME 10000 // 10 second wait time (10000 milliseconds)
Wind::Wind(void)
{
}


Wind::~Wind(void)
{
}

void Wind::wind_calibrate(){
   // set the threshold to know when someone is breathing 
    threshold = 320; 
   // during tests, through straw into apparatus reached over 400.
   // highest value reached while in apparatus extraneous breath 200 (this was under extreme conditions)
   // noise floor around 20-50 approx also system needs about 5 second's to stabalize
   
}

char Wind::waitForBreath(){
  
 /* #ifdef COMPILE_WIND_SENSOR
  #undef DEBUG
  #ifndef DEBUG
  #endif */
   //print("got to the wind sensor's first part");
   bool looping = true;
   bool passed = false;
   int breathInput = 0; // value we use to store input from the wind sensor
   // begin listening to wind speed
   
   int timeWaited = 0;
   int startTime = millis();
   
   // block until wind passes threshold or timeout occurs (wait 10 seconds)
   while(looping){
     //Serial.println("made it into the loop!");
     breathInput = analogRead(WIND_INPUT);
     timeWaited =  millis() - startTime;
     //Serial.println("time Waited is " + String(timeWaited));
     //Serial.println("wind value is " + String(breathInput));
     if(breathInput > threshold){
        passed = true;
        looping = false;
     }
     if(timeWaited > WAIT_TIME){
       looping = false;
     }
   }
   
   if(passed){
     return 'z'; // this value was chosen because the result doesn't matter
   }
   else {
     return WIND_THRESHOLD_NOT_REACHED;
   }
  /* #endif
   
   #ifdef DEBUG
   return 'z'; // assumed it passed
   #endif
   
   #ifdef COMPILE_WIND_SENSOR
   #define DEBUG
   #endif*/
}
