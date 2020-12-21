#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Challenge4.h"


void mainPassport()
{
    FILE *in_file  = fopen("/Users/mariajesusesparzapedreno/Documents/GitHub/CodingAdventCalendar/2020/passports.txt", "r"); // read only 
    Passport *myPassport = malloc(sizeof *myPassport);
    int totalValidPassports = 0;

    char originalLine[200];
    

    if (in_file == NULL)
   {
       printf("File does not exist. \n");
   }
   else
   {
       
        while (fgets(originalLine, sizeof(originalLine), in_file)) 
        {
            printf ("%s \n", originalLine);
            // check if it is the end of the passport
            if (originalLine[0] == '\n')
            {
                bool validPassport = validatePassport(myPassport);

                if (validPassport == true)
                {
                    totalValidPassports = totalValidPassports + 1;
                }
                //clean up passport struct
                myPassport = malloc(sizeof *myPassport);
            }
            else
            {
                char *endOfLine;
                endOfLine = strchr(originalLine, '\n');
                int endOfLineIndex = (int) (endOfLine - originalLine);

                if (endOfLineIndex < 1000)
                {
                    char line[endOfLineIndex];
                    for(int i = 0; i < endOfLineIndex; i = i +1)
                    {
                        line [i] = originalLine [i];
                    }
                    readPassport(line, myPassport,endOfLineIndex);
                }
                
            }
            

        }
   }

    printf(" \n Total valid passports: %i \n",totalValidPassports);

}


void readPassport(char line[], Passport* passport, int lineSize)
{
    
    char* semicolonSeparation = strchr(line, ':');
    
    int semicolonIndex = (int) (semicolonSeparation - line);

    char leftOvers [lineSize - semicolonIndex - 1];
    char passportData [3];


    for (int i= 0; i < lineSize; i = i +1)
    {
        
        if (i < semicolonIndex)
        {
           
            passportData[i] = line[i];

        }
        else if (i > semicolonIndex) //we dont want semicolong in the leftovers
        { 
            leftOvers [i - semicolonIndex -1] = line[i];
        }

    }

        if( (passportData[semicolonIndex-3]== 'b') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        {
            
            passport->byr = 1;
            
        }
        if ( (passportData[semicolonIndex-3]== 'i') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        {
            
            passport->iyr = 1;
            
        }
        if( (passportData[semicolonIndex-3]== 'e') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        {
            
            passport->eyr = 1;

        }
        if ( (passportData[semicolonIndex-3]== 'h') && (passportData[semicolonIndex-2]== 'g') && (passportData[semicolonIndex-1]== 't'))
        {
            
            passport->hgt = 1;
        
        }
        if ( (passportData[semicolonIndex-3]== 'h') && (passportData[semicolonIndex-2]== 'c') && (passportData[semicolonIndex-1]== 'l'))
        {

            passport->hcl = 1;

        }
        if ( (passportData[semicolonIndex-3]== 'e') && (passportData[semicolonIndex-2]== 'c') && (passportData[semicolonIndex-1]== 'l'))
        {
           
           passport->ecl = 1;

        }
        if ( (passportData[semicolonIndex-3]== 'p') && (passportData[semicolonIndex-2]== 'i') && (passportData[semicolonIndex-1]== 'd'))
        {
            
            passport->pid = 1;
            
        }
        if ( (passportData[semicolonIndex-3]== 'c') && (passportData[semicolonIndex-2]== 'i') && (passportData[semicolonIndex-1]== 'd'))
        {

            passport->cid = 1;

        }

/*
        printf("byr: %i \n",passport->byr);
        printf("iyr: %i \n",passport->iyr);
        printf("eyr: %i \n",passport->eyr);
        printf("hgt: %i \n",passport->hgt);
        printf("hcl: %i \n",passport->hcl);
        printf("ecl: %i \n",passport->ecl);
        printf("pid: %i \n",passport->pid);
        printf("cid: %i \n",passport->cid);
*/
    char* anotherSemicolonInLine = NULL;
    anotherSemicolonInLine = strchr(leftOvers, ':');
    
    if(anotherSemicolonInLine != NULL)
    {

       readPassport(leftOvers, passport,lineSize - semicolonIndex);
    }
}

bool validatePassport(Passport *passportStruct)
{
    bool isValidPassport = false;
    int fieldsInPassportCounter = 0;

    if (passportStruct->byr == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("byr ");
    }
    if(passportStruct->iyr == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("iyr ");
    }
    if(passportStruct->eyr == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("eyr ");
    }
    if(passportStruct->hgt == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("hgt ");
    }
    if(passportStruct->hcl == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("hcl ");
    }
    if(passportStruct->ecl == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("ecl ");
    }
    if(passportStruct->pid == 1)
    {
        fieldsInPassportCounter = fieldsInPassportCounter +1;
        printf("pid ");
    }

    /* We dont count cid as needed */
    /*
        if(passportStruct.cid == 1)
        fieldsInPassportCounter = fieldsInPassportCounter +1;
    */
   printf("fieldsInPassportCounter: %i \n",fieldsInPassportCounter);
    if (fieldsInPassportCounter == 7)
    {
        isValidPassport = true;

    }

    return isValidPassport;

}