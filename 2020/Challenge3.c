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
    int sizeOfLine = 32;
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
            printf("%s \n", originalLine);
            printf("index %i, path %c \n", horizontalIndex - (sizeOfLine  ) *copiesOfPatternCounter, originalLine[horizontalIndex - (sizeOfLine  ) *copiesOfPatternCounter]);
            if(originalLine[horizontalIndex - (sizeOfLine  ) *copiesOfPatternCounter] == tree)
            {
                treesCounter = treesCounter + 1;
            }

            horizontalIndex = horizontalIndex + 3;

            if (horizontalIndex > copiesOfPatternCounter * (sizeOfLine  ) + sizeOfLine)
            {
                copiesOfPatternCounter = copiesOfPatternCounter + 1;
            }
        }
            
    }
    printf("Number of trees %i \n", treesCounter);
}

