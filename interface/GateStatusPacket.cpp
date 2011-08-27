#include "../include/GateStatusPacket.h"
#include<ctime>
#include<iostream>


GateStatusPacket::GateStatusPacket()
{
}

GateStatusPacket::GateStatusPacket(string reg)
{
    time(&_entryTime); 
	_registration = reg;
}

GateStatusPacket::GateStatusPacket(string reg, time_t time)
{
	_entryTime = time; 
	_registration = reg;
}

time_t GateStatusPacket::GetEntryTime()
{
    return _entryTime;
}

string GateStatusPacket::GetRegistration()
{
    return _registration;
}

void GateStatusPacket::PrintTicket(string message)
{    
    
    struct tm *ptm = localtime(&_entryTime);
    cout<<"\n|========================|\n";
    cout<<"| Thank you for choosing |\n";
    cout<<"| our lot                |\n";
    cout<<"| Date:"<<((ptm->tm_mon)+1)<<"/"<<ptm->tm_mday<<"/"<< ptm->tm_year+1900<<"         |\n";
    cout<<"| Time:"<<ptm->tm_hour<<":"<<ptm->tm_min<<":"<<ptm->tm_sec<<"          |\n";
    if (message != "")
    {
        cout<<"|"<<message<<"|\n";
    }
    else
    {
        cout<<"| Vehicle:"<<_registration<<"  |\n";
    }
    cout<<"|========================|\n\n";
    return;
}