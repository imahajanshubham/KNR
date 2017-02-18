#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START 0
#define EXIT '\b'
#define MAXLENGTH 100
#define ON 1
#define OFF 0

void getInput();
void escape(char [], char []);

int main()
{
        system("clear"); 
        getInput();       
        
        return 0;
}

void getInput()
{
        int newCharacter, iterator = START;
        char strWithoutEscSeq[MAXLENGTH], strWithEscSeq[MAXLENGTH];
        
        printf("Ubuntu:~$ ");
        while((strWithoutEscSeq[iterator++] = getchar()) != EXIT);
        
        escape(strWithEscSeq, strWithoutEscSeq);
        printf("Ubuntu:~$ ");   puts(strWithEscSeq);
}

void escape(char strWithEscSeq[], char strWithoutEscSeq[])
{
        int iterator = START, secondIterator = START;
        char newCharacter[1];
        while(strWithoutEscSeq[iterator] != '\0') {
                switch(strWithoutEscSeq[iterator]) {
                        case '\t': strcat(strWithEscSeq, "\\t");          break;
                        case '\n': strcat(strWithEscSeq, "\\n");          break;
                        case '\\': strcat(strWithEscSeq, "\\\\");         break;
                        case '\b': strcat(strWithEscSeq, "\\b");          break;
                        default:   newCharacter[START] = strWithoutEscSeq[iterator];
                                   strcat(strWithEscSeq, newCharacter);   break;
                }
                                
                iterator++; 
        }
}
