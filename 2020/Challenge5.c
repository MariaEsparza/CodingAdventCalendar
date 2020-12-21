#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge5.h"

void mainBoardingPass()
{
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/seatsID.txt", "r"); // read only 
    char originalLine[LINESIZE + 2]; // (+1 is \n)


    int seatsIDs[TOTALSEATS];
    int* seatsIDsPointer;
    int counterSeatsBuffer = 0;
    

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
            //printf("finalRow %i \n", finalRow);
            //printf("finalSeatNumber %i \n", finalSeatNumber);

            seatsIDs [counterSeatsBuffer] = finalRow * 8 + finalSeatNumber;
            counterSeatsBuffer = counterSeatsBuffer + 1;

        }
        seatsIDsPointer = seatsIDs;
        orderSeat (seatsIDsPointer);

        for (int i = 1; i< TOTALSEATS; i = i +1)
        {
            if (seatsIDsPointer[i] > seatsIDsPointer[i-1] +1 )
            {
                printf("my seat ID %i \n", seatsIDsPointer[i] -1);
            }
        }

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

void orderSeat (int *seatsIDArrsy)
{
    for (int index = 0; index < TOTALSEATS; index = index + 1)
    {
        for ( int j = index + 1; j  < TOTALSEATS; j = j + 1 )
        {

            if(seatsIDArrsy[index]>seatsIDArrsy[j]) 
            {
              int temp = seatsIDArrsy[index];
              seatsIDArrsy[index] = seatsIDArrsy[j];
              seatsIDArrsy[j] = temp;
            }
        }

    }

}