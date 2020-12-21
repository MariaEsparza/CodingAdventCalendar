#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge5.h"

void mainBoardingPass()
{
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/seatsID.txt", "r"); // read only 
    char originalLine[LINESIZE + 2]; // (+1 is \n)

    int highestSeatNumber = 0;
    

    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            printf(" %s \n", originalLine);

            int rowLowThreshold = 0;
            int rowHighThreshold = 127;

            int seatLeftThreshold = 0;
            int seatRightThreshold = 7;

            int finalRow = 0;
            int finalSeatNumber = 0;

            
            for (int i = 0; i < LINESIZE ; i = i + 1)
            {
                char key;

                if (i < ROWLENGTH)
                {
                    if (originalLine[i] == 'F')
                    {
                        key = 'L';
                        finalRow = search(rowLowThreshold, rowHighThreshold, key);
                        rowHighThreshold = finalRow;
                    }
                    else
                    {
                       key = 'H'; 
                       finalRow = search(rowLowThreshold, rowHighThreshold, key);
                        rowLowThreshold = finalRow;
                    }


                }
                else
                {
                    if (originalLine[i] == 'L')
                    {
                        key = 'L';
                        finalSeatNumber = search(seatLeftThreshold, seatRightThreshold, key);
                        seatRightThreshold = finalSeatNumber;
                    }
                    else
                    {
                       key = 'H'; 
                       finalSeatNumber = search(seatLeftThreshold, seatRightThreshold, key);
                        seatLeftThreshold = finalSeatNumber;
                    }
                }

            }
            printf("finalRow %i \n", finalRow);
            printf("finalSeatNumber %i \n", finalSeatNumber);

            int seatID = finalRow * 8 + finalSeatNumber;
            printf("seatID %i \n", seatID);
            if (seatID > highestSeatNumber)
            {
                highestSeatNumber = seatID;
            }
        }
        printf("highestSeatNumber %i \n", highestSeatNumber);
   }
}

int search(int lower_bound, int upper_bound, char key)
{ 
        int mid=(lower_bound + upper_bound)/2;
        int newLow;
        int newHigh;
        if(key == 'H')
        {
            newLow = mid + 1;
            return newLow;
        }
        else if(key == 'L')
        {
            newHigh = mid ;
            return newHigh;
        }

    return -1;
}