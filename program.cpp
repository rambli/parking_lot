#include<iostream>
#include "include/GateController.h"
#include "include/GateStatusPacket.h"
#include "include/Vehicle.h"
#include "include/Parking.h"
using namespace std;

int main()
{
	Parking LotA;
	GateController gate;

	// Build parking lot
	LotA.InsertType(4);
	LotA.InsertType(6);
	LotA.InsertType(10);
#if 0
	LotA.InsertType(pair<Vehicle, int>(Vehicle(4,3000.), 15));
	LotA.InsertType(pair<Vehicle, int>(Vehicle(6,3000.), 15));
	LotA.InsertType(pair<Vehicle, int>(Vehicle(8,3000.), 15));
	LotA.InsertType(pair<Vehicle, int>(Vehicle(10,3000.), 15));
#endif
	GateStatusPacket gPacket;
	while(1)
	{
		// Loop to indicate lot is open
		gPacket = gate.GetType();

		if(EXIT == gPacket.GetOper())
		{
			gate.SetGateStatus(true);
			LotA.Decrement(gPacket.GetType());
			gate.SetGateStatus(false);
		}
		else if(ENTER == gPacket.GetOper())
		{
			if(LotA.SpaceAvailable(gPacket.GetType()))
			{
				gate.SetGateStatus(true);
				LotA.Increment(gPacket.GetType());
				gate.SetGateStatus(false);
			}
			else
			{
				cout<<"No more space available for vehicle of type %d\n",gPacket.GetType();
			}
		}
		LotA.PrintOccupancy();
	}
}
