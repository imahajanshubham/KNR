#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define START 0

void getInput(char []);
void integerToString(int, char [], int);
void reverseString(char [], int);

int main()
{
    char string[MAXLENGTH];
    int iterator = START;
    
    system("clear");
    getInput(string);

    printf("\t  <Val> %s\n", string);

    return 0;
}

void getInput(char string[])
{
    int number, width;
    printf("Ubuntu:~$ <Num> ");   scanf("%d", &number);
    printf("\t  <Wid> ");       scanf("%d", &width);
    integerToString(number, string, width);
}

void integerToString(int number, char string[], int width)
{
    int sign = number, iterator = START, digitCount = START;
    
    if(sign < 0) {
        number *= -1;
    }
    
    do {
        string[iterator++] = (number % 10) + '0';
        digitCount++;
    }while((number /= 10) > START);
    
    if(sign < START) {
        string[iterator++] = '-';
        digitCount++;
    }
    
    while(digitCount++ < width) {
        string[iterator++] = ' ';
    }

    string[iterator] = '\0';
    reverseString(string, iterator - 1);
}

void reverseString(char string[], int reverseIterator)
{
    int iterator = START;
    char tempCharacter;
    
    while(iterator < reverseIterator) {
        tempCharacter = string[iterator];
        string[iterator++] = string[reverseIterator];
        string[reverseIterator--] = tempCharacter;
    }
}
