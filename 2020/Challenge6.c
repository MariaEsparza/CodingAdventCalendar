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
    int groupAnswerBuffer[LINEMAXSIZE - 1];
    for(int j = 0; j < LINEMAXSIZE - 1; j = j + 1)
    {
        groupAnswerBuffer [j] = 0;
    }


    int groupCounter = 0;

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

                    if(groupAnswerBuffer [j] == groupCounter)
                    {
                        totalPositiveAnswers =  totalPositiveAnswers + 1;
                    }
                    // clean answersBuffer
                    groupAnswerBuffer [j] = 0;

                }
                
                groupCounter = 0;

            }
            else
            {
                char *endOfLine;
                endOfLine = strchr(originalLine, '\n');
                int endOfLineIndex = (int) (endOfLine - originalLine);

                groupCounter = groupCounter + 1;
                for (int i = 0; i < endOfLineIndex; i = i + 1)
                {
                    char questionID = originalLine [i];
                    groupAnswerBuffer[(int)questionID - ASCII_OFFSET] = groupAnswerBuffer[(int)questionID - ASCII_OFFSET] + 1;

                }
            }
            
        }

        printf("totalPositiveAnswers %i \n", totalPositiveAnswers);
   }
}