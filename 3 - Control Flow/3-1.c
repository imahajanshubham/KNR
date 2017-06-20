#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 50
#define MINIMUMNO -10000
#define START 0

void fillTheArray();
void getTheElementToBeSearched();
void searchTheElement();
void validateElementFound();

int arrayToBeSearched[MAXLENGTH], minNumber, range, iterator, targetElement, midValue, lowerValue, higherValue, position;

int main()
{
        system("clear"); 
        fillTheArray();       
        
        return 0;
}

void fillTheArray()
{
        minNumber = MINIMUMNO;
        printf("Ubuntu:~$ Range ");   scanf("%d", &range);
        for(iterator = START; iterator <= range; iterator++) {
                do {
                        printf("\t  ");   scanf("%d", &arrayToBeSearched[iterator]); 
                }while(arrayToBeSearched[iterator] < minNumber);
                
                minNumber = arrayToBeSearched[iterator];
        }
        getTheElementToBeSearched();
}

void getTheElementToBeSearched()
{
        printf("Ubuntu:~$ Value ");   scanf("%d", &targetElement);
        searchTheElement();
}

void searchTheElement()
{
        lowerValue = START; higherValue = range - 1;   midValue = (lowerValue + higherValue) / 2;
        while(lowerValue < higherValue && targetElement != arrayToBeSearched[midValue]) {
                if(targetElement > arrayToBeSearched[midValue]) lowerValue = midValue + 1;
                else higherValue = midValue - 1;
                
                midValue = (lowerValue + higherValue) / 2;   position++;
        }
        
        validateElementFound();
}

void validateElementFound()
{
        if(targetElement == arrayToBeSearched[midValue]) printf("\t  Found: %d\n", midValue);
        else printf("NILL\n");
}
