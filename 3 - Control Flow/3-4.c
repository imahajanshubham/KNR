#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

#define MAXLENGTH 100
#define START 0

void getInput(char []);
void integerToString(int, char []);
void reverseString(char [], int);

int main()
{
    char string[MAXLENGTH];
    int iterator = START;
    
    system("clear");
    getInput(string);

    printf("\t  <chr> %s\n", string);

    return 0;
}

void getInput(char string[])
{
    int number, width;
    printf("Ubuntu:~$ <int> ");   scanf("%d", &number);
    integerToString(number, string);
}

void integerToString(int number, char string[])
{
    int sign = number, iterator = START;
    
    sign = number;
    
    do {
        string[iterator++] = ABS(number % 10) + '0';
    }while((number /= 10) != START);
    
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
