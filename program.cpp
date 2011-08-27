/*======
 :: Sample C++ program to model a parking lot
 ======*/

#include<iostream>
#include "include/Vehicle.h"
#include "include/Parking.h"
using namespace std;

void BuildLot(Parking& lot)
{
    // Build parking lot
	lot.InsertType(4);
	lot.InsertType(6);
	lot.InsertType(10);
    cout<<"Done building lot\n";
    
#if 0
	LotA.InsertType(pair<Vehicle, int>(Vehicle(4,3000.), 15));
	LotA.InsertType(pair<Vehicle, int>(Vehicle(6,3000.), 15));
	LotA.InsertType(pair<Vehicle, int>(Vehicle(8,3000.), 15));
#endif
    return;
}

/*
 Function: main for parking lot controller
 Author: Rohan Ambli
 Date: 08/01/2011
 */

int main()
{
	Parking LotA;
    char enter;
    BuildLot(LotA);
    int i = 10;
    LotA.Open();
    cout<<"Lot is open!\n";
    string reg;
    float tarrif = 0.0;
    
    while(i--)
	{
        cout<<"Hit enter for ticket: ";
        cin>>enter;
        
        if(enter == 'e')
        {
            cout<<"Enter vehicle registration:";
            cin>>reg;
            Vehicle v(reg);
            cout<<"Vehicle "<<v.GetRegistration()<<" entering lot\n";
            v.SetTicket(LotA.PushForTicket(v));
            LotA.PrintOccupancy();   
        }
        else if(enter == 'x')
        {
            cout<<"Enter vehicle registration:";
            cin>>reg;
            Vehicle v(reg);
            tarrif = LotA.CalculateTarrif(v);
            if(!v)
            {
                cout<<"
            }
            cout<<v.GetRegistration()<<" needs to pay $"<<LotA.CalculateTarrif(v)<<"\n";
        }
		enter = 0;
	}

    LotA.Close();
    cout<<"Lot is now closed\n";
}
