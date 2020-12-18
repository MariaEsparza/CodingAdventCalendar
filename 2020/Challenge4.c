#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge4.h"


void mainPassport()
{
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/passports.txt", "r"); // read only 
    Passport myPassport;
    int totalValidPassports;

    char originalLine[200];
    

    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
       
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            // check if it is the end of the passport
            if (originalLine[0] == '\n')
            {
                validatePassport(myPassport, totalValidPassports);

                //clean up passport struct
                myPassport = EmptyPassport;
            }
            else
            {
                char *endOfLine;
                endOfLine = strchr(originalLine, '\n');
                int endOfLineIndex = (int) (endOfLine - originalLine);

                char line[endOfLineIndex];

                for(int i = 0; i < endOfLineIndex; i = i +1)
                {
                    line [i] = originalLine [i];
                }

                readPassport(&line, myPassport);
            }
            

        }
   }



}


void readPassport(char *line, Passport passport)
{

}

void validatePassport(Passport passportStruct,  int totalValidPassports)
{

}