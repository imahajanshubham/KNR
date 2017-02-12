#include <stdio.h>
#include <stdlib.h>

#define START 0
#define SPACE ' '
#define TAB '\t'
#define EXIT '.'

int main()
{
    int newCharacter, flag;
    system("clear");
    
    flag = START;
    while((newCharacter = getchar()) != EXIT) {
        
        if(newCharacter == SPACE) {
            if(flag == 1) {
                printf(" ");
            }
            flag = START;
        }
        else if(newCharacter == TAB) {
            flag = START;
            printf(" ");
        }
        else {
            printf("%c", newCharacter);
            flag = 1;
        }
    }
    printf(".\n");
    return 0;
}
