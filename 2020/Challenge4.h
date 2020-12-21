
#include <stdbool.h>

#define PASSPORT_SIZE   7

typedef struct Passport
{
    int byr; //(Birth Year)
    int iyr; //(Issue Year)
    int eyr; // (Expiration Year)
    int hgt; // (Height)
    int hcl; // (Hair Color)
    int ecl; // (Eye Color)
    int pid; // (Passport ID)
    int cid; //(Country ID)
}Passport;


static Passport EmptyPassport;

void mainPassport();
void readPassport(char line[], Passport *passport, int lineSize);
bool validatePassport( Passport *passportStruct);