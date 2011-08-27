#ifndef _GATE_CONTROLLER_H_
#define _GATE_CONTROLLER_H_

#include "GateStatusPacket.h"
#include "Vehicle.h"

class GateController
{
public:
    GateController();
    
    /* Returns whether the gate is open or close */
    bool GetGateStatus();
    
    /* Sets gate status */
    void SetGateStatus(bool state);
    
    /* Returns a ticket with vehicle and time information */
    GateStatusPacket GetTicket(Vehicle& v, string message);

private:
    /* Status of the gate */
    bool _gateOpenStatus;
};

#endif
