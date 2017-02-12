#include <stdio.h>

#define MAXNUMBER 20
#define START 0
#define MAXLENGTH 10

void getValuesInArray();
void calcLengthOfNo();
void addIndexInHistogram();
void fillHistogram();
void printHistogram();

char asciiValue;

int numberArray[MAXNUMBER], lengthArray[MAXNUMBER], iterator, testCase, tempValue, length, increment;
char histogramArray[MAXLENGTH][MAXNUMBER];

int main()
{
    int i, j;
    printf("\nTest Cases - ");
    scanf("%d", &testCase);
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            histogramArray[i][j] = '-';
        }
    }
    
    getValuesInArray();
    
    return 0;
}

void getValuesInArray()
{
    iterator = START;
    while(iterator < testCase) {
        printf("Value - %d: ", iterator + 1);
        scanf("%d", &numberArray[iterator++]);
    }
    
    calcLengthOfNo();
}

void calcLengthOfNo()
{
    iterator  = START;
    increment = 2;
    while(iterator < testCase) {
        tempValue = numberArray[iterator];
        length = START;
        
        while(tempValue != START) {
            length++;
            tempValue /= 10;
        }
        tempValue = iterator;
        addIndexInHistogram();
        iterator = ++tempValue;
    }
    printHistogram();
}

void addIndexInHistogram()
{
    iterator = START;
    asciiValue = '1';
    while(iterator < MAXLENGTH - 1) {
        histogramArray[iterator][START] = asciiValue++;
        iterator++;
    }
    fillHistogram();
}

void fillHistogram()
{
    iterator = START;
    while(iterator < length) {
        histogramArray[iterator][increment + 1] = '#';
        iterator++;
    }
    increment = increment + 2;
}

void printHistogram()
{
    printf("\n");
    for(iterator = 8; iterator >= 0; iterator--) {
        for(increment = START; increment < MAXNUMBER; increment++) {
            printf("%c", histogramArray[iterator][increment]);
        }
        printf("\n");
    }
}
