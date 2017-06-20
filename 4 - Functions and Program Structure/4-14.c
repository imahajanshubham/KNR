#include <stdio.h>
#include <stdlib.h>

#define swap(dataType, firstValue, secondValue) {\
                dataType tempValue;\
                tempValue   = firstValue;\
                firstValue  = secondValue;\
                secondValue = tempValue;\
            }

int main(void)
{
    char firstValue, secondValue;
    system("clear");
    
    printf("Ubuntu:~$ ");   scanf("%c %c", &firstValue, &secondValue);
    swap(char, firstValue, secondValue);
    
    printf("\t  %c %c\n", firstValue, secondValue);
    
    return 0;
}
