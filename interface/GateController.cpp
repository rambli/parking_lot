#include<iostream>
#include "../include/GateController.h"
#include "../include/GateStatusPacket.h"
#include "../include/Vehicle.h"
using namespace std;

GateController::GateController()
{
	_gateOpenStatus = false;
    return;
}

bool GateController::GetGateStatus()
{
	return _gateOpenStatus;
}
void GateController::SetGateStatus(bool status)
{
	_gateOpenStatus = status;
    return;
}

GateStatusPacket GateController::GetTicket(Vehicle& v, string message)
{
    GateStatusPacket ticket(v.GetRegistration());
    ticket.PrintTicket(message);
    return ticket;
}

