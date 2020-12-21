#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge6.h"



void detectAnswersInGroup ()
{
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/customs.txt", "r"); // read only 

    
    char originalLine[LINEMAXSIZE +1];
    int totalPositiveAnswers = 0;
    
    //buffer that will contain a flag per letter per group
    bool groupAnswerBuffer[LINEMAXSIZE - 1];
    memset(groupAnswerBuffer, 0, LINEMAXSIZE - 1);

    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
       
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            printf ("%s \n", originalLine);

            // check if it is the end of the group
            if (originalLine[0] == '\n')
            {
                // count the number of yes in the group
                for(int j = 0; j < LINEMAXSIZE - 1; j = j + 1)
                {
                    if(groupAnswerBuffer [j] == true)
                    {
                        printf("%i ", j);
                        totalPositiveAnswers = totalPositiveAnswers +1;
                    }

                }
                // clean answersBuffer
                printf("\n");
                memset(groupAnswerBuffer, 0, LINEMAXSIZE - 1);
            }
            else
            {
                char *endOfLine;
                endOfLine = strchr(originalLine, '\n');
                int endOfLineIndex = (int) (endOfLine - originalLine);

                for (int i = 0; i < endOfLineIndex; i = i + 1)
                {
                    char questionID = originalLine [i];

                    if(groupAnswerBuffer[questionID - ASCII_OFFSET] == false)
                    {
                        groupAnswerBuffer[questionID - ASCII_OFFSET] = true;
                    }

                }
            }
            
        }
        printf("totalPositiveAnswers %i \n", totalPositiveAnswers);
   }
}