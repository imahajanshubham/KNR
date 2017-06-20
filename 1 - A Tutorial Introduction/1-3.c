#include <stdio.h>
#include <stdlib.h>

int main()
{
        int lower,upper,step;
        int celsius,fahr;
        system("clear");

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;

        while( fahr <= upper)
        {
                celsius =  5 * (fahr - 32) / 9;
                printf("Ubuntu:`$ *F -> %d\t*C -> %d\n",fahr,celsius);
                fahr = fahr + step;
        }

        return 0;
}
