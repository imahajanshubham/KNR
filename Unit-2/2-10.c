#include <stdio.h>
#include <stdlib.h>

#define ON 1
#define OFF 0

int convertToLowerCase();

int newCharacter, flag = ON;

int main()
{
        system("clear");
        
        printf("Ubuntu:~$ ");
        while((newCharacter = getchar()) != '\n')
        {
                if(flag == ON) {
                        printf("\t  ");   flag = OFF;
                }
                
                printf("%c", newCharacter = convertToLowerCase());
        }
        
        printf("\n");
        return 0;
}

int convertToLowerCase()
{
        return (newCharacter >= 'A' && newCharacter <= 'Z') ? (newCharacter + 'a' - 'A') : (newCharacter);
}
