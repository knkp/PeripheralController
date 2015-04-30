#include <Arduino.h>
#include "Breath.h"
#include "Cabinet.h"
#include "Wind.h"

Cabinet
		cab;

Wind
	speed;

Breath::Breath(void)
{
	breath;
}


Breath::~Breath(void)
{
}

void Breath::DoYourBest(int &breath) 
{
	Serial.println(" Please provide breath sample. ");
	breath = analogRead(A1);

	speed.WindSensor(breath);

	if(breath == 1) // yes
	{
		Pass(breath);
	}

	if(breath == 0) // no
	{
		Faile();
	}	
}

// Protocall if the pass
void Breath::Pass(int &breath) 
{
	Serial.println(" Passed \n\n");

	cab.Check(breath);
}

// Protocall if the faile
void Breath::Faile() 
{
	Serial.println(" Failed  \n\n");

	cab.Closed();
}
