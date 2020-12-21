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
            int recursiveCounter = 0;
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
                    readPassport(line, myPassport,endOfLineIndex, recursiveCounter);
                }
                
            }
            

        }
   }

    printf(" \n Total valid passports: %i \n",totalValidPassports);

}


void readPassport(char line[], Passport* passport, int lineSize, int cntRecursivity)
{
    
    char* semicolonSeparation = strchr(line, ':');
    
    int semicolonIndex = (int) (semicolonSeparation - line);
    int leftOversSize = lineSize - semicolonIndex - 1;
    char leftOvers [leftOversSize];
    char passportData [3];


    for (int i= 0; i < lineSize; i = i +1)
    {
        
        if (i < semicolonIndex)
        {
            passportData[i] = line[i];
        }
        else if (i > semicolonIndex) //we dont want semicolon in the leftovers
        { 
            leftOvers [i - semicolonIndex -1] = line[i];
        }

    }

        if( (passportData[semicolonIndex-3]== 'b') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        { 
            char year [4];
            for (int j= 0; j<YEAR_LENGTH; j = j +1)
            {
                year[j] = leftOvers[j];
            }
            passport->byrData = atoi(year);
            if( (passport->byrData >= 1920) && (passport->byrData <= 2002))
            {
                passport->byr = 1;
            }
        }
        if ( (passportData[semicolonIndex-3]== 'i') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        {
            passport->iyr = 1;
            char year [YEAR_LENGTH];
            for (int j= 0; j<YEAR_LENGTH; j = j +1)
            {
                year[j] = leftOvers[j];
            }
            passport->iyrData = atoi(year);
            if( (passport->iyrData >= 2010) && (passport->iyrData <= 2020))
            {
                passport->iyr = 1;
            }
        }
        if( (passportData[semicolonIndex-3]== 'e') && (passportData[semicolonIndex-2]== 'y') && (passportData[semicolonIndex-1]== 'r'))
        {
            passport->eyr = 1;
            char year [YEAR_LENGTH];
            for (int j= 0; j<YEAR_LENGTH; j = j +1)
            {
                year[j] = leftOvers[j];
            }
            passport->eyrData = atoi(year);
            if( (passport->eyrData >= 2010) && (passport->eyrData <= 2030))
            {
                passport->eyr = 1;
            }
        }
        if ( (passportData[semicolonIndex-3]== 'h') && (passportData[semicolonIndex-2]== 'g') && (passportData[semicolonIndex-1]== 't'))
        {
            char* endHeight = strchr(leftOvers, ' ');
            int endHeightIndex = 0;
            
            if(endHeight != NULL)
            {
                endHeightIndex = (int) (endHeight - leftOvers);
            }
            else
            {
                endHeightIndex = leftOversSize - cntRecursivity;
            }

            char height [endHeightIndex-2];
            char heightUnits [2];
            for (int j= 0; j < endHeightIndex; j = j +1)
            {
                if (j < endHeightIndex - 2)
                {
                    height[j] = leftOvers[j];
                }
                else
                {
                    heightUnits[endHeightIndex - j - 1] = leftOvers[j];
                }
                
            }   
            
            passport->hgtData = atoi(height);
            
            // if it is cm 
            if( (heightUnits[1] == 'c') && (heightUnits[0] == 'm'))
            {
                // it is valid only if (150 < height< 193)
                if ( (passport->hgtData > 150) && (passport->hgtData < 193) )
                {
                    passport->hgt = 1;  
                }
            }
            // check if it is in "in"
            if( (heightUnits[1] == 'i') && (heightUnits[0] == 'n'))
            {
                // it is valid only if (59 < height< 76)
                if ( (passport->hgtData > 59) && (passport->hgtData < 76) )
                {
                    passport->hgt = 1;  
                }
            }
                 
        }

        if ( (passportData[semicolonIndex-3]== 'h') && (passportData[semicolonIndex-2]== 'c') && (passportData[semicolonIndex-1]== 'l'))
        {
            char* endHairColor = strchr(leftOvers, ' ');
            int hairColorIndex = 0;
            
            if(endHairColor != NULL)
            {
                hairColorIndex = (int) (endHairColor - leftOvers);
            }
            else
            {
                hairColorIndex = leftOversSize - cntRecursivity;
            }
 

            bool hairColorValid = true;
            char hairColor [hairColorIndex];
            for (int j= 0; j < hairColorIndex; j = j +1)
            {
                hairColor[j] = leftOvers[j];

                if(hairColor[0] != '#')
                {
                    hairColorValid = false;
                }

                if ((j > 0) && (hairColor[j] != '0') && (hairColor[j] != '1') && (hairColor[j] != '2') && (hairColor[j] != '3') && (hairColor[j] != '4') && (hairColor[j] != '5') && (hairColor[j] != '6') && (hairColor[j] != '7') && (hairColor[j] != '8') && (hairColor[j] != '9') 
                    && (hairColor[j] != 'a') && (hairColor[j] != 'b') && (hairColor[j] != 'c') && (hairColor[j] != 'd') && (hairColor[j] != 'e') && (hairColor[j] != 'f'))
                {
                    hairColorValid = false;
                }
            }   
            if( hairColorValid == true)
            {
                passport->hcl = 1;
            }  

        }

        if ( (passportData[semicolonIndex-3]== 'e') && (passportData[semicolonIndex-2]== 'c') && (passportData[semicolonIndex-1]== 'l'))
        {        
           
            for (int j= 0; j < EYECOLOR_LENGTH; j = j +1)
            {
                passport->eclData[j] = leftOvers[j];
            }
            if(strcmp(passport->eclData, "amb") || strcmp (passport->eclData, "blu") || strcmp(passport->eclData, "brn") || strcmp(passport->eclData, "gry") || strcmp(passport->eclData, "grn") || strcmp(passport->eclData, "hzl") || strcmp(passport->eclData, "oth"))
            {
                passport->ecl = 1;
            }
        }
        if ( (passportData[semicolonIndex-3]== 'p') && (passportData[semicolonIndex-2]== 'i') && (passportData[semicolonIndex-1]== 'd'))
        {            
            
            char* endPassportID = strchr(leftOvers, ' ');
            int endPassportIDIndex = 0;
            
            if(endPassportID != NULL)
            {
                endPassportIDIndex = (int) (endPassportID - leftOvers);
            }
            else
            {
                endPassportIDIndex = leftOversSize - cntRecursivity;
            }
 

            bool passportIDValid = true;
            char passportID [endPassportIDIndex];
            for (int j= 0; j < endPassportIDIndex; j = j +1)
            {
                passportID[j] = leftOvers[j];
                
                if ((passportID[j] != '0') && (passportID[j] != '1') && (passportID[j] != '2') && (passportID[j] != '3') && (passportID[j] != '4') && (passportID[j] != '5') && (passportID[j] != '6') && (passportID[j] != '7') && (passportID[j] != '8') && (passportID[j] != '9') )
                {
                    passportIDValid = false;
                }
            }   
            //passport->pidData = passportID;

            if( passportIDValid == true)
            {
                passport->pid = 1;
            }   
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
        cntRecursivity = cntRecursivity +1;

       readPassport(leftOvers, passport,lineSize - semicolonIndex, cntRecursivity);
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