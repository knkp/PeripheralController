
#include "RPSS.h"

#define heaterSelPin 2
#define BREATHALYZER_INPUT A1
#define WAIT_TIME 3000 // 3 second wait time (3000 milliseconds)

// uncomment the following to debug any issues with the breathalyzer:
//#define DEBUGGINGBREATH

Breath::Breath(void)
{
}


Breath::~Breath(void)
{
}
void Breath::breath_calibrate(){
   // set the threshold to the correct value 
   
   // in experiments, once sensor heats up, it settles at around 700-800 and drops below 200 if I wash my mouth out with a shot
   // of fireball whiskey -- SC, no more time to be more detailed, although now that I can see the behaviour it is certainly possible
   // to come up with an exact estimate of the BAC from the breath
    threshold = 350;
    // waiting for sensor to warm-up:
    
    // tell the breathalyzer to begin warming up:
    pinMode(heaterSelPin, OUTPUT);
    digitalWrite(heaterSelPin,LOW);
    
    bool warmedUp = false;
    while(!warmedUp)
    {
      int sensorValueInput = analogRead(BREATHALYZER_INPUT);
      if( sensorValueInput > 500 )
      {
#ifdef DEBUGGINGBREATH
        Serial.print("still warming up, current value: ");
        Serial.print(sensorValueInput);
        Serial.println(", needs to be above 500");
#endif
        warmedUp = true;
      } 
    }
}

char Breath::check_patron_BAC(){
   bool pass;
   bool looping = true;
   bool passed = false;
  
   float sensorValue; // value we use to store input from the wind sensor
   // begin listening to wind speed
   
   int timeWaited = 0;
   int startTime = millis();
   
   // block until wind passes threshold or timeout occurs (wait 10 seconds)
   while(looping){
     //Serial.println("made it into the loop!");
     
     sensorValue = analogRead(BREATHALYZER_INPUT);
#ifdef DEBUGGINGBREATH
       Serial.println("current value: ");
       Serial.println(sensorValue);
#endif

     timeWaited =  millis() - startTime;
     
     if(sensorValue < threshold){
#ifdef DEBUGGINGBREATH
       Serial.println("dropped below threshold, failed");
#endif
        passed = false;
        looping = false;
     }
     if(timeWaited > WAIT_TIME){
#ifdef DEBUGGINGBREATH
       Serial.println("not enough alochol detected to mark as drunk, passed");
#endif

       looping = false;
       passed = true;
     }
   }
     
    
     // accumulate enough data from the sensor to perform a BAC check
    
     // determine if they have passed or failed and pass the results up the machine
    
    if(passed)
       return BREATHALYZER_TEST_PASS;
    else
       return BREATHALYZER_TEST_FAIL;
}
