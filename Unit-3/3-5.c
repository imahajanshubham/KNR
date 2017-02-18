#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define START 0

void getInput(char []);
void IntegerToBaseString(int, char [], int);
void reverseString(char [], int);

int main()
{
    char string[MAXLENGTH];
    int iterator = START;
    
    system("clear");
    getInput(string);

    printf("\t   <Value> %s\n", string);

    return 0;
}

void getInput(char string[])
{
    int number, base;
    printf("Ubuntu:~$ <Number> ");   scanf("%d", &number);
    printf("\t      <Base> ");         scanf("%d", &base);
    IntegerToBaseString(number, string, base);
}

void IntegerToBaseString(int number, char string[], int base)
{
    int sign = number, digit, iterator = START;
    
    if(sign < 0) {
        number *= -1;
    }
    
    do {
        digit = number % base;
        string[iterator++] = (digit <= 9) ? digit + '0': digit + 'a' - 10;
    }while((number /= base) > START);
    
    if(sign < START) {
        string[iterator++] = '-';
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
