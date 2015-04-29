#include <Arduino.h>
#include "Cabnet.h"
#include "Breath.h"

Cabnet::Cabnet(void)
{
	lock,
	unlock,
	breath;
}

Cabnet::~Cabnet(void)
{
}

// Will check to see if finger ID match's the box
void Cabnet::Check(int &breath) 
{
	if(breath == 1) // yes
	{
		Open();
	}

	if(breath == 0) // no
	{
		Closed();
	}	
}

// Protocal to open the box
void Cabnet::Open()
{
	lock = 1; 
	unlock = 0;

	Serial.println(" Your box will open. ");
	Serial.println(" \n\n Thank you for using The Responsible Patrons Storage System \n\n");
}

// Protocall to keep box closed 
void Cabnet::Closed()
{
	lock = 0;
	unlock = 1;

	Serial.println(" Management will be by to assist you. \n");
}

// Holds all cabnet data
void Cabnet::Basket() 
{

}