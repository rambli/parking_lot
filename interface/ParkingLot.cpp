#include "../include/ParkingLot.h"

ParkingLot::ParkingLot()
{
	spotCount.clear();
	maxCount = 20;
}

ParkingLot::~ParkingLot()
{
}

float ParkingLot::CalculateTarrif()
{
	return 0.;
}

bool ParkingLot::VehicleAllowed(int type)
{
	return true;
}

void ParkingLot::PrintOccupancy()
{
	map<int,int>::iterator it;

	for(it = spotCount.begin(); it != spotCount.end(); it++)
		cout<<(*it).first<<"->"<<(*it).second<<"\n";
}

void ParkingLot::InsertType(int type)
{
	//typename std::map<int, int>::const_iterator it;
	map<int, int>::const_iterator it;

	// check if type already exists befor inserting it
	it = spotCount.find(type);
	
	if(it == spotCount.end())
	{
		//spotCount.insert[type] = 0;
		spotCount.insert(std::pair<int, int>(type, 0));
	}
	PrintOccupancy();
}

void ParkingLot::Increment(int type)
{
	map<int,int>::iterator iter;

	iter = spotCount.find(type);
	if( (iter != spotCount.end()) && SpaceAvailable(type) )
		(*iter).second++;
}

void ParkingLot::Decrement(int type)
{
        map<int,int>::iterator it;

        it = spotCount.find(type);
        if( (it != spotCount.end()) && ((*it).second > 0) )
                (*it).second--;
	else
	{
		if((*it).second == 0)
			cout<<"Someone slipped in without logging an entry, catch them!\n";
	}
}

bool ParkingLot::SpaceAvailable(int type)
{
	map<int,int>::iterator it;
	bool availability = false;
	it = spotCount.find(type);
	if(it != spotCount.end())
	{
		if((*it).second < maxCount)
			availability =  true; 
	}
	return (availability);
}
