#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 100
#define START 0

int getLine(char []);
void reverse(char [],int ,int);

int main(void)
{
    char string[MAXLENGTH];
    system("clear");

    printf("ubuntu:~$ ");   getLine(string);
    reverse(string,0,strlen(string));
    printf("\t  %s\n", string);
    
    return 0;
}

int getLine(char string[])
{
    int iterator, newCharacter;

    for(iterator = START; iterator < MAXLENGTH - 1 && (newCharacter = getchar()) != EOF && newCharacter != '\n'; ++iterator) {
        string[iterator] = newCharacter;
    }

    if(newCharacter=='\n') {
        string[iterator++]='\n';
    }

    string[iterator]='\0';
}

void reverse(char string[], int iterator, int length)
{
    int newCharacter, limit;

    limit = length - (iterator + 1);
    if(iterator < limit) {
        newCharacter     = string[iterator];
        string[iterator] = string[limit];
        string[limit]    = newCharacter;

        reverse(string,++iterator,length);
    }
}
