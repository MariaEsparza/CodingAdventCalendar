#include <math.h>
#include <stdio.h>
#include "Challenge1.h"


void entriesReportSearch ()
{
    int sizeReport = sizeof(expensesReport)/sizeof(expensesReport[0]);
    int x = 0;
    int y = 0;
    int z = 0;
    int result = 0;
    for (int i= 0; i < sizeReport; i=i+1)
    {
        x = expensesReport[i];
        for (int j= 0; j < sizeReport; j=j+1)
        {
            y = expensesReport[j];

            for (int k= 0; k < sizeReport; k=k+1)
            {
                z = expensesReport[k];

                if (x + y + z == 2020)
                {
                    result = x*y*z;
                    printf("Result %d \n", result);
                }
            }
        }
    }

}

