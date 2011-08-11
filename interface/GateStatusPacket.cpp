#include "../include/GateStatusPacket.h"

GateStatusPacket::GateStatusPacket()
{
	_oper = ENTER; 
	_type = 4;
}

GateStatusPacket::GateStatusPacket(GATE_OPERATION oper, int type)
{
	_oper = oper;
	_type = type;
}

void GateStatusPacket::SetOper(GATE_OPERATION oper)
{
	_oper = oper;
}
void GateStatusPacket::SetType(int type)
{
	_type = type;
}

GATE_OPERATION GateStatusPacket::GetOper()
{
	return _oper;
}

int GateStatusPacket::GetType()
{
	return _type;
}
