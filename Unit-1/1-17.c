#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define START 0
#define NULLCHAR '\0'
#define NEWLINE '\n'

int newCharacter, stringSize, iterator, length;
char string[MAXSIZE];

int getNewLine();
void printString();

int main()
{
        system("clear");
        
        while((length = getNewLine()) > 0) {
                if(length > 10) {
                        printString();
                        stringSize = START - 1;
                }
                else {
                        printf("---\n");
                }
        }
        
	return 0;
}

int getNewLine()
{
        for(stringSize = START; stringSize < MAXSIZE - 1 && (newCharacter = getchar()) != EOF && newCharacter != NEWLINE; ++stringSize) {
	        string[stringSize] = newCharacter;
	}
        
        if(newCharacter == NEWLINE) {
	        string[stringSize] == newCharacter;
	}
	string[++stringSize] == NULLCHAR;
	
	return stringSize;
}

void printString()
{
        for(iterator = START; iterator < stringSize; iterator++) {
	        printf("%c", string[iterator]);
	}
	printf("\n---\n");
}
