#ifndef _PARKING_H_
#define _PARKING_H_
#include "ParkingLot.h"

class Parking : public ParkingLot
{
public:
    /* Over-riding function since this lot charges for parking */
    float CalculateTarrif(Vehicle& v);
    
    /* Over-riding function since this lot would like to prevent
     access for certain kinds of vehicles */
    bool VehicleAllowed(Vehicle& v);
    
private:
    
    /* Hourly rate charged by this lot */
    float _hourlyRate;
};

#endif
