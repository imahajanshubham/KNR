#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define NEWLINE '\n'
#define NULLCHAR '\0'
#define START 0
#define ON 1
#define OFF 0

void getLine(char []);
int stringPBRK(char [], char []);

int iterator, newCharacter, flag;

int main()
{
        int poistion;
        char firstString[MAXLENGTH], secondString[MAXLENGTH];
        
        system("clear");        
        
        printf("1. 1st String: ");       getLine(firstString);
        printf("2. 2nd String: ");       getLine(secondString);

        printf("---\nPosition: %d\n", stringPBRK(firstString, secondString));
    
        return 0;
}

void getLine(char string[])
{
        for(iterator = START; iterator < MAXLENGTH - 1; iterator++) {
                newCharacter = getchar();
                if(newCharacter == NEWLINE) {
                        break;
                }
                else if(newCharacter == EOF) {
                        break;
                }
                else {
                        string[iterator] = newCharacter;
                }
        }
        string[iterator] = NULLCHAR;
}

int stringPBRK(char firstString[], char secondString[])
{
        int position;
        iterator = START;
        flag = OFF;
        
        while(firstString[iterator] != NULLCHAR) {
                if(firstString[iterator] == secondString[iterator]) {
                        position = iterator++;
                        flag = ON;
                        break;
                }
                iterator++;
        }
        
        if(flag == 0) {
                return -1;
        }
        return position + 1;
}
