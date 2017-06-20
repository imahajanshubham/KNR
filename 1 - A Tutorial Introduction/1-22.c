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

int newCharacter, stringSize, iterator, length, spaceCount, temp, flag, newLineCount, limitReached;
char string[MAXSIZE], tempCharacter;

int getNewLine();
void printString();
void storeIndex();

int main()
{
        tempCharacter = '0';
        system("clear");
        
        while((length = getNewLine()) > 0) {
                printString();
        }
        
	return 0;
}

int getNewLine()
{       
        spaceCount = temp = flag = newLineCount = START;       
        limitReached = OFF;                 
                
        for(stringSize = START; stringSize < MAXSIZE - 1 && (newCharacter = getchar()) != EOF && newCharacter != NEWLINE; ++stringSize) {
	        if(newCharacter == '.')
	        {
	                string[stringSize++] = newCharacter;
	                string[stringSize++] = NEWLINE;
	                temp = START;
	        }
	        else if(newCharacter == SPACE) {
	                if(temp > 80) {
                                string[stringSize++] = NEWLINE;
                                temp = START;
                        }
                        
	                if(temp++ != START) {
	                        if(flag == ON) {
	                                string[stringSize++] = SPACE;
	                                flag = OFF;
	                        }
	                        
	                        
	                }
	        }
	        else {
	                string[stringSize] = newCharacter;
	                flag = ON;
	                temp++;
	        }
	}
        
        if(newCharacter == NEWLINE) {
	        string[stringSize] = newCharacter;
	}
	string[++stringSize] = NULLCHAR;
	temp++;
	
	return stringSize;
}
void printString()
{
        int lineCount = START;
        
        printf("\n---\n");
        for(iterator = START; iterator < stringSize - 1; iterator++) {
	        if(iterator == 0) {
	                printf(" %d. ", lineCount + 1);
	                lineCount++;
	        }
	        else {
	                if(string[iterator] == '\n') {
	                        printf("%c", string[iterator]);
	                        if(lineCount < 9) {
	                                printf(" ");
	                        }
	                        printf("%d. ", lineCount + 1);
	                        lineCount++;
	                }
	                else if(string[iterator] == '.') {
	                        printf("%c", string[iterator]);
	                        if(lineCount < 9) {
	                                printf("\n ");
	                        }
	                        printf("%d. ", lineCount + 1);
	                        lineCount++;
	                }
	                else {
	                        printf("%c", string[iterator]);
	                }
	                string[iterator] = NULLCHAR;
	        }
	}
	printf("---\n");
}
