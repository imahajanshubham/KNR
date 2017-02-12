/*TAB = 8 WHite Spaces.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define START 0

#define NULLCHAR '\0'
#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'
#define TABWIDTH 8

#define ON 0
#define OFF 1

int newCharacter, stringSize, iterator, length, spaceCount;
char string[MAXSIZE], tempCharacter;

int getNewLine();
void printString();
void storeWhiteSpaces_using_Tab();

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
        spaceCount = START;        
        
        for(stringSize = START; stringSize < MAXSIZE - 1 && (newCharacter = getchar()) != EOF && newCharacter != NEWLINE; ++stringSize) {
	        if(newCharacter == SPACE) {
	                if(++spaceCount % 8 == 0) {
	                storeWhiteSpaces_using_Tab();
	                        spaceCount = 0;
	                }
	        }
	        else {
	                string[stringSize] = newCharacter;
	        }
	}
        
        if(newCharacter == NEWLINE) {
	        string[stringSize] = newCharacter;
	}
	string[++stringSize] = NULLCHAR;
	
	return stringSize;
}

void storeWhiteSpaces_using_Tab()
{
        string[stringSize++] = TAB;
}

void printString()
{
        for(iterator = START; iterator < stringSize; iterator++) {
	        printf("%c", string[iterator]);
	}
	printf("\n---\n");
}
