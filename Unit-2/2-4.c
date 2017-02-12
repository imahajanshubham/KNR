#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define NEWLINE '\n'
#define NULLCHAR '\0'
#define START 0
#define ON 1
#define OFF 0

void getLine(char []);
void squeeze(char [], char []);
void putString(char []);

int value, iterator, newCharacter, flag, secondIterator, temp;

int main()
{
        char firstString[MAXLENGTH], secondString[MAXLENGTH];
        value = START;
        flag = OFF;
        system("clear");        
        
        printf("1. 1st String: ");       getLine(firstString);
        printf("2. 2nd String: ");       getLine(secondString);

        squeeze(firstString, secondString);
        printf("---\nSqueezed String: ");       putString(firstString);
    
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

void squeeze(char firstString[], char secondString[])
{
        iterator = secondIterator = START;
        while(firstString[iterator] != NULLCHAR) {
                if(firstString[iterator] == secondString[secondIterator]) {
                        
                        temp = iterator;
                        
                        while(firstString[iterator] != NULLCHAR) {
                                firstString[iterator] = firstString[iterator++ + 1];
                        }
                        iterator = temp;
                        
                        if(firstString[iterator] == NULLCHAR) {
                                break;
                        }
                        secondIterator++;
                }
                else {
                        iterator++;
                        secondIterator++;
                }
                
        }
}

void putString(char string[])
{
        iterator = 0;
        
        while(string[iterator] != NULLCHAR) {
                printf("%c", string[iterator++]);
        }
        printf("\n");
}
