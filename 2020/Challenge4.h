
#include <stdbool.h>

#define PASSPORT_SIZE       7
#define YEAR_LENGTH         4
#define EYECOLOR_LENGTH     3
#define PASSPORTID_LENGTH   9

typedef struct Passport
{
    int byr; //(Birth Year)
    int byrData; //four digits; at least 1920 and at most 2002.
    int iyr; //(Issue Year)
    int iyrData; //four digits; at least 2010 and at most 2020.
    int eyr; // (Expiration Year)
    int eyrData; //four digits; at least 2020 and at most 2030.
    int hgt; // (Height)
    int hgtData;
        //If cm, the number must be at least 150 and at most 193.
        //If in, the number must be at least 59 and at most 76.
    int hcl; // (Hair Color)
    char hclData[6]; //a # followed by exactly six characters 0-9 or a-f.
    int ecl; // (Eye Color)
    char eclData [3]; //exactly one of: amb blu brn gry grn hzl oth.
    int pid; // (Passport ID)
    char pidData [PASSPORTID_LENGTH]; // a nine-digit number, including leading zeroes.
    int cid; //(Country ID)
    int cidData; //ignored, missing or not.
}Passport;


static Passport EmptyPassport;

void mainPassport();
void readPassport(char line[], Passport *passport, int lineSize, int cntRecursivity);
bool validatePassport( Passport *passportStruct);
bool checkData();