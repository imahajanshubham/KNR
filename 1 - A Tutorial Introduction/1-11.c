#include <stdio.h>
#include <stdlib.h>

#define START 0
#define IN 1
#define OUT 0

int main(void)
{
    int newCharacter, noOfLines, noOfWords, noOfCharacters, state;
    system("clear");
    state = OUT;
    noOfLines = noOfWords = noOfCharacters = START;
    
    printf("Ubuntu:~$ ");
    while ((newCharacter = getchar()) != EOF) {
        ++noOfCharacters;
        if (newCharacter == '\n') {
            ++noOfLines;
            printf("\t  ");
        }
        if (newCharacter == ' ' || newCharacter == '\n' || newCharacter == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++noOfWords;
        }
    }
    printf("\n\t  %d | %d | %d\n", noOfLines, noOfWords, noOfCharacters);
}
