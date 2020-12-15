#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge3.h"


int readGeology (int horizontalStep, int verticalStep)
{
    
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/treesList.txt", "r"); // read only 

    int treesCounter = 0;
    int copiesOfPatternCounter = 0;
    int sizeOfLine = 50;
    int endOfLineIndex = 31;
    int horizontalIndex = 0;
    char originalLine[sizeOfLine];
    char tree = '#';

    int verticalLineCounter = 0;
    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            if( (verticalLineCounter % verticalStep) == 0)
            {
                //printf("verticalLine counter %i \n",verticalLineCounter);

            
                char line[endOfLineIndex];

                for (int i= 0; i < endOfLineIndex; i = i +1)
                {
                    line[i] = originalLine[i];
                }


                if(line[horizontalIndex - (endOfLineIndex ) *copiesOfPatternCounter] == tree)
                {
                    treesCounter = treesCounter + 1;
 
                }

                horizontalIndex = horizontalIndex + horizontalStep;

                if (horizontalIndex >= copiesOfPatternCounter * (endOfLineIndex ) + endOfLineIndex)
                {
                    copiesOfPatternCounter = copiesOfPatternCounter + 1;
                }
            }
            verticalLineCounter = verticalLineCounter +1;
        }
        
            
    }
    printf("Number of trees %i \n", treesCounter);
    return treesCounter;
}

void checkTreesStadistics()
{

    int stepsRight = 1;
    int stepsDown = 1;
    int oneRightOneDown = readGeology(stepsRight, stepsDown);

    stepsRight = 3;
    int threeRightOneDown = readGeology(stepsRight, stepsDown);

    stepsRight = 5;
    int fiveRightOneDown = readGeology(stepsRight, stepsDown);
    
    stepsRight = 7;
    int sevenRightOneDown = readGeology(stepsRight, stepsDown);

    stepsRight = 1;
    stepsDown = 2;
    int oneRightTwoDown = readGeology(stepsRight, stepsDown);


}