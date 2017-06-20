#include <stdio.h>
#include <stdlib.h>

#define TOTALASCIIVALUES 128
#define START 0

int main(void)
{
    int c,i,j;

    int character[TOTALASCIIVALUES];
    
    for(i=START;i<TOTALASCIIVALUES;++i)
        character[i] = START;
    
    while((c=getchar())!=EOF)
        ++character[c];

    for(i=START;i<TOTALASCIIVALUES;++i)
    {
        putchar(i);
        
        for(j=START;j<character[i];++j)
            putchar('*');
        
        putchar('\n');
    }
    
    return 0;
}

