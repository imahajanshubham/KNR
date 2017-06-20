#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define NULLCHAR '\0'
#define FAIL - 1
#define START 0

void getInput(char []);
int strindex(char [],char []);

int main()
{
    int index;
    char string[MAXLENGTH], patternString[MAXLENGTH];
    system("clear");
    
    printf("Ubuntu:~$ ");   getInput(string);
    printf("\t  ");         getInput(patternString);
    index = strindex(string, patternString);

    switch(index) {
        case -1: printf("\t  <lol> %d\n", index);       break;
        default: printf("\t  <SUCCESS> %d\n", index);   break;
    }
    
    return 0;
}

void getInput(char string[])
{
    int newCharacter, iterator = START;
    while((newCharacter = getchar()) != '\n') {
        string[iterator++] = newCharacter;
    }
    string[iterator] = '\0';
}

int strindex(char string[],char patternString[])
{
    int iterator, patternIterator, stringIterator;
    for(iterator = START; string[iterator] != NULLCHAR; iterator++) {
            for(stringIterator = iterator, patternIterator = START; patternString[patternIterator] != NULLCHAR && string[stringIterator] == patternString[patternIterator]; stringIterator++, patternIterator++);
            
            if(patternString[patternIterator] == NULLCHAR && patternIterator > START) {
                return iterator;
            }
    }
    
    return FAIL;
}
