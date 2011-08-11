#ifndef _GATE_CONTROLLER_H_
#define _GATE_CONTROLLER_H_

#include "GateStatusPacket.h"

class GateController
{
	public:
		GateController();
		//GateController(int minWheels, int maxWheels);
		bool GetGateStatus();
		void SetGateStatus(bool state);
		GateStatusPacket GetType();
	private:
		void QueryCustomer();
		bool _gateOpenStatus;
		GateStatusPacket _packet;
};

#endif
