#include "RPSS.h"
Wind::Wind(void)
{
	breath,
	windSpeed;
}


Wind::~Wind(void)
{
}

void Wind::WindSensor(int &breath)
{
	Serial.println(" Enter wind speed"); //for testing 
	windSpeed = analogRead(A4);

	if(windSpeed == 1)
	{
		breath = 1;
	}

	if(windSpeed == 0)
	{
		breath = 0;
	}
}
