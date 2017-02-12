#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000
#define NEWLINE '\n'
#define NULLCHAR '\0'
#define START 0
#define ON 1
#define OFF 0

void getLine(char []);
int hexadecimalToInteger(char []);

int value, iterator, newCharacter, flag, value;

int main()
{
        char string[MAXLENGTH];
        value = START;
        flag = ON;
        system("clear");        
        
        printf("HEX Value: ");       getLine(string);
        value = hexadecimalToInteger(string);

        printf("INT Value: %d\n", value);
    
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
        string[++iterator] = NULLCHAR;
}

int hexadecimalToInteger(char string[])
{
        int hexadecimalDigit;
        iterator = START;
            
        if(string[iterator] == '0') {
                ++iterator;
                if(string[iterator] == 'x' || string[iterator] == 'X') {
                        ++iterator;
                }
        }
        
        while(flag == ON)
        {
                if((string[iterator] >= '0') && (string[iterator] <= '9')) {
                        hexadecimalDigit = string[iterator] - '0';
                }
                else if((string[iterator] >= 'a') && (string[iterator] <= 'f')) {
                        hexadecimalDigit = string[iterator] - 'a' + 10;
                }
                else if((string[iterator] >= 'A') && (string[iterator] <= 'F')) {
                        hexadecimalDigit = string[iterator] - 'A' + 10;
                }
                else {
                        string[iterator] = '\0';
                        flag = OFF;
                }
                
                if(flag == ON) {
                        value = 16 * value + hexadecimalDigit;
                }
                iterator++;
        }
        
        return value;
}
