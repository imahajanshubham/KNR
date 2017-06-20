#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define START 0
#define NULLCHAR '\0'
#define NEWLINE '\n'

void getLine();
void printLine();

int iterator, newCharacter;
char string[MAXLENGTH];

int main()
{
        system("clear");        
        
        printf(" Input: ");       getLine();
        printf("String: ");        printLine();
        
        return 0;
}

void getLine()
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
        string[iterator + 1] = NULLCHAR;
}

void printLine()
{
        iterator = START;
        
        while(string[iterator] != NULLCHAR) {
                printf("%c", string[iterator++]);
        }
        printf("\n");
}

