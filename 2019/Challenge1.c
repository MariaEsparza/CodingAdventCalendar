#include <math.h>
#include <stdio.h>
#include "Challenge1.h"


int FuelCounterUpper ()
{
    int totalFuel= 0;
    for (int i= 0; i < 100; i++)
    {

        totalFuel = totalFuel + fuelCalculation(modulesMass[i], 0);
        
    }
    



    return totalFuel;
}

int fuelCalculation (int Init_Mass, int fuel)
{
    int total = 0;
    int mass =  floor (Init_Mass / divider) - offset;
    if  (mass > 0)
    {
        fuel = fuel + mass;
        total =  fuelCalculation(mass,fuel);
    }
    else
    {
        return fuel;
    }
    
    
    return total;
}