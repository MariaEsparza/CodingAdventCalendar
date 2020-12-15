#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge3.h"


void readGeology ()
{
    
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/treesList.txt", "r"); // read only 
    int horizontalIndex = 0;
    int treesCounter = 0;
    int copiesOfPatternCounter = 0;
    int sizeOfLine = 50;
    int endOfLineIndex = 31;
    char originalLine[sizeOfLine];
    char tree = '#';
    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            
            char line[endOfLineIndex];

            for (int i= 0; i < endOfLineIndex; i = i +1)
            {
                line[i] = originalLine[i];
            }
            printf("%s", line);
            printf("\n real index %i, index in line %i\n", horizontalIndex, horizontalIndex - (endOfLineIndex ) *copiesOfPatternCounter);
            

            if(line[horizontalIndex - (endOfLineIndex ) *copiesOfPatternCounter] == tree)
            {
                treesCounter = treesCounter + 1;
                printf("tree \n");
            }

            horizontalIndex = horizontalIndex + 3;
            

            if (horizontalIndex >= copiesOfPatternCounter * (endOfLineIndex ) + endOfLineIndex)
            {
                copiesOfPatternCounter = copiesOfPatternCounter + 1;
            }
        }
            
    }
    printf("Number of trees %i \n", treesCounter);
}

