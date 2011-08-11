#ifndef _GATE_STATUS_PACKET_H_
#define _GATE_STATUS_PACKET_H_

typedef enum
{
	ENTER,
	EXIT
}GATE_OPERATION;


class GateStatusPacket
{
	public:
		GateStatusPacket();
		GateStatusPacket(GATE_OPERATION oper, int type);
		void SetOper(GATE_OPERATION oper);
		void SetType(int type);
		GATE_OPERATION GetOper();
		int GetType();
	private:
		GATE_OPERATION _oper;
		int _type;
};

#endif
