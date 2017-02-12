/*TAB = 8 WHite Spaces.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define START 0

#define NULLCHAR '\0'
#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'

#define ON 0
#define OFF 1

int newCharacter, stringSize, iterator, length, temp;
char string[MAXSIZE], tempCharacter;

int getNewLine();
void printString();
void storeTab_using_WhiteSpaces();

int main()
{
        system("clear");
        
        while((length = getNewLine()) > 0) {
                if(length > 10) {
                        printString();
                        stringSize = START - 1;
                }
                else if(length < 1) {
                        printf("---\n");
                }
        }
        
	return 0;
}

int getNewLine()
{
        for(stringSize = START; stringSize < MAXSIZE - 1 && (newCharacter = getchar()) != EOF && newCharacter != NEWLINE; ++stringSize) {
	        if(newCharacter == TAB) {
	                storeTab_using_WhiteSpaces();
	        }
	        else {
	                string[stringSize] = newCharacter;
	        }
	}
        
        if(newCharacter == NEWLINE) {
	        string[stringSize] == newCharacter;
	}
	string[++stringSize] == NULLCHAR;
	
	return stringSize;
}

void storeTab_using_WhiteSpaces()
{
        for(iterator = START; iterator < 8; iterator++) {
                string[stringSize++] = SPACE;
        }
        iterator = 0;
}

void printString()
{
        for(iterator = START; iterator < stringSize; iterator++) {
	        printf("%c", string[iterator]);
	}
	printf("\n---\n");
}
