#pragma once
#include "RPSS.h"

class Wind
{
	friend class Breath;

	private://can not be accesed
	double 
		breath,
		windSpeed;

public:
	Wind(void);
	~Wind(void);

	void WindSensor(int &breath);
};

