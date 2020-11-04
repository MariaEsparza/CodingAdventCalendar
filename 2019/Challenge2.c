#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge2.h"

int noun = 0;
int verb = 0;
int HaltProgramLimit = 99;


void ProgramAlarm (int  array[], int size)
{
    
    for (int i= 0; i < size; i=i+4)
    {
       
       switch (array[i])
       {
        case 1:
            array[array[i+3]] = array[array[i+1]] + array[array[i+2]];
            break;
        case 2:
            array[array[i+3]] = array[array[i+1]] * array[array[i+2]];
            break;
        case 99: 
            //printf("Halt Program \n");
            break;
        default:
            //printf("Default case: no command was found \n");
            break;

       }       
    }
}

void searchForNounAndVerb (int size)
{
     int tempArray [size];

    for (int noun = 0 ; noun <= HaltProgramLimit; noun++)
    {
      
        for (int verb = 0; verb<= HaltProgramLimit; verb++)
        {
            
            memcopy(tempArray, IntCode0, size);
            

            tempArray [1] = noun;
            tempArray [2] = verb;
            

            ProgramAlarm(tempArray, size);
            
            if (tempArray[0] == 19690720)
            {
                int result = 100* noun +  verb;
                printf("good job \n");
                printf("result %d \n", result);
      
            }
        }

    }

}

void testPrints( int  array[], int size)
{
    
    for (int i= 0; i < size; i++)
    {
        printf("%d \n", array[i]);
    }

}

void memcopy (int arrayOutput [], int arrayInput [], int length)
{
    for (int i= 0; i < length; i++)
    {
        arrayOutput[i] = arrayInput[i];
    }
}