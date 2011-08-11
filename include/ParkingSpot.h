template<class T>
class ParkingSpot
{
	public:
		ParkingSpot(){};
		ParkingSpot(T type, int status);
		T GetType();
		void SetType(T type);
		int GetStatus();
		void SetStatus(int status);
	private:
		T _type;
		int _status;
}

template<class T>
ParkingSpot<T>::ParkingSpot()
{
	_status = 0; // Available and can accomodate any type of T
}

template<class T>
ParkingSpot<T>::ParkingSpot(T type, int status)
{
	_type = type;
	_status = status;
}

template<class T>
T ParkingSpot<T>::GetType()
{
	return _type;
}

template<class T>
void ParkingSpot<T>::SetType()
{
	_type = type;
}

template<class T>
int ParkingSpot<T>::GetStatus()
{
	return _status;
}

template<class T>
void ParkingSpot<T>::SetStatus(int stat)
{
	_status = stat;
}
