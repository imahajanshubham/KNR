#include <stdio.h>
#include <stdlib.h>

#define START 1
#define ON 1
#define OFF 0

int main()
{
        int newCharacter, iterator, flag = ON;
        system("clear");

        printf("Ubuntu:~$ ");
        
        while((newCharacter = getchar()) != EOF)
        {
                if(newCharacter == ' ' || newCharacter == '\n' || newCharacter == '\t') {
                        printf("\n");   if(newCharacter == '\n') flag = ON;   printf("\t  ");
                }
                else {
                        if(flag == ON) {
                                printf("\t");
                                for(iterator = START; iterator <= 10; iterator++) printf("%3d", iterator);
                                printf("\n\t  ");   flag = OFF;
                        }
                        printf("*  ");
                }
        }
        
        return 0;
}
