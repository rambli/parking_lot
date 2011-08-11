#include "../include/Vehicle.h"

Vehicle::Vehicle()
{
	_wheels = 4;
	_weight = 3000.;
}

Vehicle::Vehicle(int o, float w)
{
	if((o < 3) || (o > 18))
	{
		
	}
	_wheels = o;
	_weight = w;
}

bool Vehicle::GetPermit()
{
	return _permit;
}

int Vehicle::GetWheels()
{
	return _wheels;
}

float Vehicle::GetWeight()
{
	return _weight;
}

void Vehicle::SetWheels(int o)
{
	_wheels = o;
}

void Vehicle::SetWeight(float o)
{
	_weight = o;
}
