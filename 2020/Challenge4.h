
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
void readPassport(char *line, Passport passport);
void validatePassport( Passport passportStruct, int totalValidPassports);