#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle
{
	public:
		Vehicle();
		Vehicle(int o, float w);
		int GetWheels();
		float GetWeight();
		void SetWheels(int o);
		void SetWeight(float w);
		bool GetPermit();
	private:
		int _wheels;
		float _weight;
		bool _permit;
};
#endif // _VEHICLE_H_
