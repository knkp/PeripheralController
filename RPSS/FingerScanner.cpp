#include "Boards.h"
#include <Arduino.h>
#include "FingerScanner.h"
#include "Cabinet.h"
#include "Breath.h"

FingerScanner::FingerScanner(void)
{
	scan,
	breath,
	lock,
	unlock;
}


FingerScanner::~FingerScanner(void)
{
}

//Check's data base for finger ID
void FingerScanner::Scan(int &scan, int &breath)
{
	Serial.println(" Hello, Patron \n\n");
	Serial.println(" Welcome to The Responsible Patrons Storage System \n\n");

	Serial.println(" Please place finger on scanner.  ");
	scan = analogRead(A0);
	//Serial.println(scan);

	if(scan == 1) // yes
	{
		Go(breath);
	}

	if(scan == 0) // no
	{
		Stop(scan);
	}	
}

// Protocall if not in data base
void FingerScanner::Stop(int &scan)
{
	Cabinet
		cab;

	int count = 0;

	Serial.println(" You are not in the system. \n");
	Serial.println(" Please place finger on scanner ");
	scan = analogRead(A0);
	//Serial.println(scan);
	
	while(scan == !1) // IF the person is not in the system an they dont place tere finger on the scanner
	{
		if(count <= 3)
		{
			Serial.println("  Unable to read. \n");
			Serial.println(" Please place finger on scanner agein. ");
			scan = analogRead(A0);
			//Serial.println(scan);
		}

		if(count >= 3)
		{
			Scan(scan,breath);
		}

		count++;
	}

	cab.Open();
}

// Protocall if in data base
void FingerScanner::Go(int &breath)
{
	Breath
		dyb;

	dyb.DoYourBest(breath);
}

// Holds all finger scan data
void FingerScanner::BlackBox() 
{
	
}
