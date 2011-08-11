#include<iostream>
#include "../include/GateController.h"
#include "../include/GateStatusPacket.h"
using namespace std;

GateController::GateController()// : _gateOpenStatus(false)
{
	_gateOpenStatus = false;	// Closed by default
	_packet.SetType(0);		// Vehicle not allowed by default
}

void GateController::QueryCustomer()
{
	int wheels = 0;
	char oper = 'E';
	cout<<"Enter(E)/Exit(X)?\n";
	cin>>oper;
	if(('E' == oper) || ('e' == oper))
	{
		_packet.SetOper(ENTER);
	}
	else if(('X' == oper) || ('x' == oper))
	{
		_packet.SetOper(EXIT);
	}
	cout<<"Enter number of wheels:";
	cin>>wheels;
	_packet.SetType(wheels);
}

GateStatusPacket GateController::GetType()
{
	QueryCustomer();
	return (_packet);
}


bool GateController::GetGateStatus()
{
	return _gateOpenStatus;
}
void GateController::SetGateStatus(bool status)
{
	_gateOpenStatus = status;
}

