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
void reverseString();

int main()
{
        system("clear");
        
        while((length = getNewLine()) > START + 1) {
                if(length > 10) {
                        reverseString();
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

void reverseString()
{
        iterator = START;
        temp = stringSize;
        stringSize--;

        while(iterator <= stringSize) {
                newCharacter = string[iterator];
	        string[iterator++] = string[stringSize];
	        string[stringSize--] = newCharacter;
        }
        
        stringSize = temp;
}

void printString()
{
        for(iterator = START; iterator < stringSize; iterator++) {
	        printf("%c", string[iterator]);
	}
	printf("\n---\n");
}
