#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    printf("Fahrenheit\tCelsius\n\n");
    while(fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%.3f\t\t%.3f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
    return 0;
}
