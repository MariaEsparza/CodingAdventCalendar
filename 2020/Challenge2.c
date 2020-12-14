#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge2.h"


void readPasswords ()
{
    
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/passwordsList.txt", "r"); // read only 
    
   char line[35];
   if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
       

        while (fgets(line, sizeof(line), in_file)) {
            /* note that fgets don't strip the terminating \n, checking its
            presence would allow to handle lines longer that sizeof(line) */
            //printf("%s", line);
            
            char *separationBetweenMaxAndMin;
            separationBetweenMaxAndMin = strchr(line, '-');
            int indexOfSeparation = (int) (separationBetweenMaxAndMin - line);
            char minOccurrenceLetterInPassword[indexOfSeparation];


            for (int i = 0; i < indexOfSeparation ; i=i+1)
            {
                minOccurrenceLetterInPassword[i] = line[i];  
            }
            //printf("%s \n", minOccurrenceLetterInPassword);
             
            char *separationBetweenMaxAndLetter;
            separationBetweenMaxAndLetter = strchr(line, ' ');
            int SpaceIndex = (int) (separationBetweenMaxAndLetter - line);
            int sizeMax = SpaceIndex - indexOfSeparation - 1;

            char maxOccurrenceLetterInPassword[sizeMax];
            int indexMax = 0;
            for (int j = indexOfSeparation + 1 ; j < SpaceIndex; j=j+1)
            {

                maxOccurrenceLetterInPassword[indexMax] = line[j];
                indexMax = indexMax + 1; 
                
            }
            char Letter = line[SpaceIndex + 1];

            char* endOfLine;
            endOfLine = strchr(line, '\n');
            int endOfLineIndex = (int) (endOfLine - line);
            int passwordIndex = 0;
            int passwordSize = endOfLineIndex -1 - SpaceIndex - 3;
            char password [passwordSize];

            printf ("Start password %i \n", SpaceIndex + 4);
            printf("password size %i \n",passwordSize);
            for (int z = SpaceIndex + 4; z < endOfLineIndex; z= z+1)
            {
                password [passwordIndex] = line[z];
                passwordIndex = passwordIndex +1;
            }
            //printf("%s \n", password);
            //char* password = &line + SpaceIndex + 3;
            
            

        }
        /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */
       
   }
   fclose(in_file);
}

