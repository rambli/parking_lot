#include<iostream>
#include<string>
#include "../include/Vehicle.h"

Vehicle::Vehicle()
{
    cout<<"ERROR: Vehicle must have a valid registration\n";
    exit(1);
}

Vehicle::Vehicle(string reg, int o)
{
    _registration = reg;
	_type = o;
}

string Vehicle::GetRegistration()
{
    return _registration;
}

void Vehicle::SetRegistration(string reg)
{
    _registration = reg;
}

bool Vehicle::GetPermit()
{
	return _permit;
}

int Vehicle::GetType()
{
	return _type;
}

void Vehicle::SetType(int o)
{
	_type = o;
}

void Vehicle::SetTicket(GateStatusPacket ticket)
{
	_ticket = ticket;
}

GateStatusPacket Vehicle::GetTicket()
{
	return _ticket;
}