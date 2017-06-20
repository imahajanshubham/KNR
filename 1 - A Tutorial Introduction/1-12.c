#include <stdio.h>
#include <stdlib.h>

#define START 0
#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'
#define EXIT '.'

int main()
{
    int newCharacter, lineCount, flag;
    system("clear");
    
    lineCount = flag = START;

    printf("%d. ", lineCount);
    
    while((newCharacter = getchar()) != EXIT) {
    
        if(newCharacter == NEWLINE) {
            flag = START;
            printf("%d. ", ++lineCount);
        }
        else if(newCharacter == SPACE) {
            if(flag == 1) {
                printf("\n");
                printf("%d. ", ++lineCount);
            }
            flag = START;
        }
        else if(newCharacter == TAB) {
            flag = START;
            printf("\n");
            printf("%d. ", ++lineCount);
        }
        else {
            if(flag == START) {
                printf("\n");
                printf("%d. ", ++lineCount);
            }
            printf("%c", newCharacter);
            flag = 1;
        }
    }
    
    printf("\n\n");
    
    return 0;
}
