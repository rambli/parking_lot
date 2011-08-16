#ifndef _PARKING_H_
#define _PARKING_H_
#include "ParkingLot.h"

class Parking : public ParkingLot
{
        public:
                float CalculateTarrif();
                bool VehicleAllowed(int type);
	private:
		float hourlyRate;
		
};

#endif
