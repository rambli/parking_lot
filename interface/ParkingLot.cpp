#include "../include/ParkingLot.h"

ParkingLot::ParkingLot()
{
	_spotCount.clear();
    _billingInfo.clear();
	_maxCount = 20;
	_hourlyRate = 0.0;
}

ParkingLot::~ParkingLot()
{
}

void ParkingLot::Open()
{
    _status = true;
    _gate.SetGateStatus(_status);
}

void ParkingLot::Close()
{
    _status = false;
    _gate.SetGateStatus(_status);
}

//Base parking is free, don't bother calculating number of hours
float ParkingLot::CalculateTarrif(Vehicle& v)
{
	return (_hourlyRate*0);
}

// Allow vehicles of all type by default
bool ParkingLot::VehicleAllowed(Vehicle& v)
{
	return true;
}

void ParkingLot::PrintOccupancy()
{
	map<int,int>::iterator it;

	for(it = _spotCount.begin(); it != _spotCount.end(); it++)
		cout<<(*it).first<<"->"<<(*it).second<<"\n";
}

void ParkingLot::InsertType(int type)
{
	//typename std::map<int, int>::const_iterator it;
	map<int, int>::const_iterator it;

	// check if type already exists before inserting it
	it = _spotCount.find(type);
	
	if(it == _spotCount.end())
	{
		//spotCount.insert[type] = 0;
		_spotCount.insert(std::pair<int, int>(type, 0));
	}
	//PrintOccupancy();
}

bool ParkingLot::Increment(Vehicle& v)
{
	map<int,int>::iterator iter;

	iter = _spotCount.find(v.GetType());
	if( (iter != _spotCount.end()) && SpaceAvailable(v) )
    {
		(*iter).second++;
        return true;
    }
    else
    {
        return false;
    }
}

void ParkingLot::Decrement(Vehicle& v)
{
    map<int,int>::iterator it;

    it = _spotCount.find(v.GetType());
    if( (it != _spotCount.end()) && ((*it).second > 0) )
    {
        (*it).second--;
        _billingInfo.erase(v.GetRegistration());
        cout<<"Deleted vehicle "<<v.GetRegistration()<<" information\n";
    }
	else
	{
		if((*it).second == 0)
			cout<<"Someone slipped in without logging an entry, catch them!\n";
	}
}

void ParkingLot::AddBillingInfo(Vehicle& v, GateStatusPacket &p)
{
    _billingInfo[v.GetRegistration()] = p;
}

GateStatusPacket ParkingLot::RetrieveBillingInfo(Vehicle& v)
{
    cout<<"Retrieving billing info for "<<v.GetRegistration()<<" \n";
    if(_billingInfo.count(v.GetRegistration()))
    {
        return(_billingInfo[v.GetRegistration()]);
    }
    else
    {
        return (GateStatusPacket(""));
    }
}

bool ParkingLot::SpaceAvailable(Vehicle& v)
{
	map<int,int>::iterator it;
	bool availability = false;
	it = _spotCount.find(v.GetType());
	if(it != _spotCount.end())
	{
		if((*it).second < _maxCount)
			availability =  true; 
	}
	return (availability);
}

GateStatusPacket ParkingLot::PushForTicket(Vehicle& v)
{
    GateStatusPacket ticket;
    bool result = SpaceAvailable(v);
    string ticketString("");
    
    if(true == result)
    {
        Increment(v);
        _gate.SetGateStatus(false);
        _gate.SetGateStatus(true);
    }
    else
    {
        ticketString = "No more space available";
    }
    ticket = _gate.GetTicket(v, ticketString);
    
    /* This vehicle is getting admitted, store billing info against
     this registration */
    if(true == result)
    {
        AddBillingInfo(v, ticket);
    }
    return (ticket);
}