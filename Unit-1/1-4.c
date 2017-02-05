#include <stdio.h>

int main()
{
    float  fr, cs ;
    
    do {
        printf("Celsius: ");
        scanf("%f", &cs);
        
        fr = (9 * cs) / 5 + 32;
        printf("Fahrenhiet: %.5f.\n\n", fr);
    }while(cs != 0.0);
    
    return 0;
}
