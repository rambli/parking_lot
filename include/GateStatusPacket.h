#ifndef _GATE_STATUS_PACKET_H_
#define _GATE_STATUS_PACKET_H_

#include "../include/GateStatusPacket.h"
#include<string>
using namespace std;

class GateStatusPacket
{
public:
    /* Default constructor - Do not call this */
    GateStatusPacket();
    
    /* Constructor taking only registration, current time is used */
    GateStatusPacket(string reg);
    
    /* Constructor taking both time and registration */
    GateStatusPacket(string reg, time_t time);
    
    /* Get the entry time on this ticket */
    time_t GetEntryTime();
    
    /* The the registration on this ticket */
    string GetRegistration();
    
    /* Print out the ticket */
    void PrintTicket(string message);
    
private:
    /* Entry time of the vehicle */
    time_t _entryTime;
    
    /* Vehicle registration */
    string _registration;
};

#endif
