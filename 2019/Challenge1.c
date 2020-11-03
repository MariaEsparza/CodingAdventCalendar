#include <math.h>
#include <stdio.h>
#include "Challenge1.h"


int FuelCounterUpper ()
{
    int totalFuel= 0;
    int newFuelAdded= 0;
    for (int i= 0; i < 100; i++)
    {
        totalFuel = totalFuel + fuelCalculation(modulesMass[i]);
        
    }
    
    newFuelAdded = totalFuel;
    while( 0 < fuelCalculation(newFuelAdded) )
    {
        printf("%d \n", newFuelAdded);
        newFuelAdded = fuelCalculation(newFuelAdded);
        
        totalFuel = totalFuel + newFuelAdded;   
    }


    return totalFuel;
}

int fuelCalculation (int Mass)
{
    int fuel = 0;
    fuel =  floor (Mass / divider) - offset;
    return fuel;
}