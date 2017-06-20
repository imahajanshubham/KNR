#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
        int fahrenheit;
        system("clear");
        
        printf(" *F     *C\n");
        for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP) {
                printf("%3d %6.1f\n", fahrenheit, (5.0/9.0)*(fahrenheit-32));
        }
        
        return 0; 
}       
