#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include<ctime>
#include<string>
#include"GateStatusPacket.h"
using namespace std;

class Vehicle
{
public:
    /* Default construction should not be used */
    Vehicle();
    
    /* Create a vehicle with a registration. Defaults to type=4 */
    Vehicle(string reg)
    {
        _registration = reg ;
        _type = 4;
    }
    
    /* Create a vehicle with registration and type */
    Vehicle(string reg, int type);
    
    /* Get Vehicle registration */
    string GetRegistration();

    /* Set Vehicle registration */
    void SetRegistration(string reg);
    
    /* Returns the type of this vehicle */
    int GetType();
    
    /* Sets the type of this vehicle */
    void SetType(int type);
    
    /* Check if this vehicle has a permit for this parking lot */
    bool GetPermit();
    
    /* Set the ticket for this vehicle with registration and time 
     information at entry time */
    void SetTicket(GateStatusPacket ticket);
    
    /* Returns the ticket assigned at entry time during exit */
    GateStatusPacket GetTicket();
    
    /* Print vehicle information */
    void printInfo();
    
private:
    /* Vehicle registration */
    string _registration;
    
    /* Kind of vehicle */
    int _type;
    
    /* The ticket assigned to this vehicle */
    GateStatusPacket _ticket;
    
    /* If vehicle has a permit */
    bool _permit;
};
#endif // _VEHICLE_H_
