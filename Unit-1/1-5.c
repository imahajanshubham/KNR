#include <stdio.h>

#define START 300
#define END 0
#define STEP 20
#define DIFFERENCE 32

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    fahr = lower;
    printf("Fahrenheit\tCelsius\n\n");
    
    for(fahr = START; fahr >= END; fahr = fahr - STEP) {
        celsius = 5 * (fahr - DIFFERENCE) / 9;
        printf("%.3f\t\t%.3f\n", fahr, celsius);
    }
    
    return 0;
}
