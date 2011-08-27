#include "../include/Parking.h"
#include "../include/Vehicle.h"

float Parking::CalculateTarrif(Vehicle& v)
{
    float tarrif = 0.;
    if(v.GetRegistration() == "")
    {
        tarrif = 25.;
    }
    else
    {
        /* Get entry time and compare w/ current time, multiple with the daily
         rate to get tarrif */
        GateStatusPacket p = RetrieveBillingInfo(v);

        if(p.GetRegistration() == "")
        {
            cout<<"No such vehicle on record\n";
            return 0.0;
        }
        
        /* If vehicle has permit, no charge */
        if(v.GetPermit())
        {
            return 0.0;
        }
        
        /* Get entry time */
        time_t entryTime = p.GetEntryTime();
        struct tm *etm = localtime(&entryTime);
        
        /* Get current time */
        time_t currentTime;
        time(&currentTime);
        struct tm *ctm = localtime(&currentTime);
        
        int days = ctm->tm_mday - etm->tm_mday;
        int months = ctm->tm_mon - etm->tm_mon;
        
        if(months > 1)
        {
            int totalDays = ((ctm->tm_mon * 30) + (ctm->tm_mday)) - 
                            ((etm->tm_mon * 30) + (etm->tm_mday)) ;
            tarrif = totalDays * 5.0;
        }
        else if((days > 10) && (months < 1))
        {
            tarrif = days * 5.50;
        }
        else if((days > 1) && (days < 10))
        {
            /* More than 1 day and less than 10 */
            tarrif = 6.50 * days;
        }
        else if(days < 1)
        {
            int hours = ctm->tm_hour - etm->tm_hour;
            int minutes = ctm->tm_min - etm->tm_min;
            int total_mins = (hours*60)+minutes;
            float chargableTime = total_mins / 60.0;
            cout<<"Chargable time is "<<chargableTime<<" \n";
            /* Less than 30 minutes is free */
            //if(chargableTime < 0.5)
            //{
            //    tarrif = 0.0;
            //}
            //else
            //{
                tarrif = 7.0;
            //}
        }    
    }
    Decrement(v);
    return tarrif;
}

bool Parking::VehicleAllowed(Vehicle& v)
{
    return true;
}
