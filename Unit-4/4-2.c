#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100
#define START 0

void getInput(char []);
double custom_atof(char []);

int main(void)
{
    float value;
    char string[MAXLENGTH];
    system("clear");
    
    printf("Ubuntu:~$ ");   getInput(string);
    printf("\t  %f\n", value = custom_atof(string));

    return 0;
}

void getInput(char string[])
{
    int iterator = START, newCharacter;
    while((newCharacter = getchar()) != '\n' && iterator < MAXLENGTH - 1) {
        string[iterator++] = newCharacter;
    }
    
    string[iterator] = '\0';
}

double custom_atof(char string[])
{
    int iterator = START, sign;
    float exponent;
    double value, power;
    while(string[iterator] == ' ') {
        iterator++;
    }
    
    switch(string[iterator]) {
        case '-': iterator++;   sign = -1;   break;
        case '+': iterator++;   sign =  1;   break;
        default :               sign =  1;   break;
    }
    for(value = 0.0; string[iterator] >= 48 && string[iterator] <= 57; iterator++) {
        value = value * 10 + (string[iterator] - '0');
    }
    
    if(string[iterator] == '.') {
        iterator++;
        for(power = 1.0; string[iterator] >= 48 && string[iterator] <= 57; iterator++) {
            value = value * 10 + (string[iterator] - '0');
            power *= 10.0;
        }
    }
    
    value = (sign * value) / power;
    if(string[iterator] == 'e' || string[iterator] == 'E') {
        iterator++;   power = 1.0;
        switch(string[iterator]) {
            case '-': iterator++;   sign = -1;   break;
            case '+': iterator++;   sign =  1;   break;
            default :               sign =  1;   break;
        }
        
        for(exponent = START; string[iterator] != '\0' && string[iterator] >= 48 && string[iterator] <= 57; iterator++) {
            exponent = exponent * 10 + (string[iterator] - '0');
        }
        
        for(iterator = 0; iterator < exponent; iterator++) {
            power *= 10;
        }
        
        switch(sign) {
            case -1: value /= power;   break;
            case  1: value *= power;   break;
        }
    }
    
    return value;
}
