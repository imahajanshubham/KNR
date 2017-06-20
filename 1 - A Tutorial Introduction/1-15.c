#include <stdio.h>
#include <stdlib.h>

void temperatureConversion();

float fahr, celsius;
int lower = 0, upper = 300, step = 20;

int main()
{
    system("clear");
    fahr = lower;
    
    printf("Fahrenheit\tCelsius\n\n");
    temperatureConversion();
    
    return 0;
}

void temperatureConversion()
{
    if(fahr > upper) {
        return;
    }
        celsius = 5 * (fahr - 32) / 9;
        printf("%.3f\t\t%.3f\n", fahr, celsius);
        fahr = fahr + step;
    temperatureConversion();
}
