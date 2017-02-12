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

int newCharacter, stringSize, iterator, length, flag;
char string[MAXSIZE];

int getNewLine();
void printString();

int main()
{
        system("clear");
        
        while((length = getNewLine()) > START + 1) {
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
        flag = ON;
        for(stringSize = START; stringSize < MAXSIZE - 1 && (newCharacter = getchar()) != EOF && newCharacter != NEWLINE; ++stringSize) {
	        if(newCharacter == SPACE || newCharacter == TAB) {
	                if(flag == ON) {
	                        string[stringSize] = SPACE;
	                }
	                flag = OFF;
	        }
	        else {
	                string[stringSize] = newCharacter;
	                flag = ON;
	        }
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
