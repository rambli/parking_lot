#ifndef _PARKING_LOT_H_
#define _PARKING_LOT_H_

#include <map>
#include <iostream>
#include "Vehicle.h"
using namespace std;

class ParkingLot
{
	public:
		ParkingLot();
		void InsertType(int type);
		void Increment(int type);
		void Decrement(int type);
		bool SpaceAvailable(int type);
		void PrintOccupancy();
		virtual int CalculateTarrif();
	private:
		map<int, int> spotCount;
		int maxCount;
};

#endif
