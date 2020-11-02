#include <math.h>
#include <stdio.h>
#include "Challenge1.h"


int FuelCounterUpper ()
{
    int totalFuel= 0;

    for (int i= 0; i < 100; i++)
    {
        totalFuel = totalFuel + floor (modulesMass[i] / 3) - 2;
    }

    return totalFuel;
}