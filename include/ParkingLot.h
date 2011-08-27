#ifndef _PARKING_LOT_H_
#define _PARKING_LOT_H_

#include <map>
#include <iostream>
#include "Vehicle.h"
#include "GateController.h"
using namespace std;

class ParkingLot
{
public:
    ParkingLot();
    virtual ~ParkingLot();
    
    /* Adds an allowable vehicle type which can park in this lot */
    void InsertType(int type);
    
    /* Opens the lot for business */
    void Open();
    
    /* Closes the lot, no more vehicle allowed to enter or exit */
    void Close();
    
    /* Customer needs to get a ticket to enter the parking lot,
     this assigns a ticket */
    GateStatusPacket PushForTicket(Vehicle& v);
    
    /* Check if any space is available in the parking lot */
    bool SpaceAvailable(Vehicle& v);
    
    /* Print current occupancy of the lot */
    void PrintOccupancy();
    
    /* Calculate the tarrif for parking. Base type is free parking
     Inheriting classes should over-ride this if they want to charge
     for parking. */
    virtual float CalculateTarrif(Vehicle& v);
    
    /* Check if a vehicle is allowed. Base class allows all types of 
     vehicles. Inheriting classes should over-ride this function if they
     want to impose any restrictions on the kinds of vehicles allowed. */
    virtual bool VehicleAllowed(Vehicle& v);
    
    /* Increment the vehicle count */
    bool Increment(Vehicle& v);
    
    /* Decrement the vehicle count */
    void Decrement(Vehicle& v);
    
    /* Private function to add vehicle to billing info */
    void AddBillingInfo(Vehicle& v, GateStatusPacket &p);
    
    /* Function to get back the billing info for this vehicle
     from our stored data */
    GateStatusPacket RetrieveBillingInfo(Vehicle& v);
    
private:
    /* Keeps track of number of vehicles of a particular type.
     TODO: Convert map<int, int> to be map<Vehicle, int> */
    map<int, int> _spotCount;
    
    /* Keep track of GateStatusPacket on a per-vehicle basis to
     keep track of data on our side */
    map<string, GateStatusPacket> _billingInfo;
    
    /* Maximum available spots */
    int _maxCount;
    
    /* Hourly rate of parking */
    float _hourlyRate;
    
    /* Lot status */
    bool _status;
    
    /* Gate controller for this parking lot */
    GateController _gate;
};

#endif
