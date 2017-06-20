#include <stdio.h>
#include <stdlib.h>

#define START 0
#define SPACE ' '
#define TAB '\t'
#define BACKSLASH '\\'
#define EXIT '.#include <stdio.h>
#include <stdlib.h>

#define START 0
#define SPACE ' '
#define TAB '\t'
#define BACKSLASH '\\'
#define EXIT '\n'

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
            printf("\\t");
        }
        else if(newCharacter == BACKSLASH) {
            printf("\\\\");
        }
        else {
            printf("%c", newCharacter);
            flag = 1;
        }
    }
    printf(".\n");
    return 0;
}'

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
            printf("\\t");
        }
        else if(newCharacter == BACKSLASH) {
            printf("\\\\");
        }
        else {
            printf("%c", newCharacter);
            flag = 1;
        }
    }
    printf(".\n");
    return 0;
}
