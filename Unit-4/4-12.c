#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 100
#define STEP 10
#define START

void itoa(int, char []);


int main(void)
{
    int number;
    char string[MAXLEN];
    system("clear");

    printf("ubuntu:~$ ");   scanf("%d", &number);
    itoa(number,string);
    printf("%s\number",string);

    return 0;
}

void itoa(int number, char string[])
{
    static int iterator;

    if(number/STEP)
        itoa(number/STEP, string);
    else {
        iterator = START;
        if(number < 0) {
            string[iterator++]='-';
        }
    }

    string[iterator++] = abs(number) % STEP + '0';
    string[iterator] = '\0';
}
