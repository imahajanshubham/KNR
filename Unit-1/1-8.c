/*To stop the String from taking input, Just place '@' at the end of your
paragraph and hit enter :)
*/

#include <stdio.h>
#include <stdlib.h>

#define START 0
#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'
#define EXIT '@'

int main()
{
    int newCharacter, lineCount, spaceCount, tabCount, characterCount, wordCount, flag, totalCharCount;
    system("clear");
    
    lineCount = spaceCount = tabCount = characterCount = wordCount = flag = totalCharCount = START;
    
    printf("lol.c (~/) - gedit\n");
    printf("---\n");
    printf("\n %d. ", ++lineCount);
    
    while((newCharacter = getchar()) != EXIT) {
    
        if(newCharacter == NEWLINE) {
            if(flag == 1) {
                wordCount++;
            }
            
            lineCount++;
            flag = START;
            
            if(lineCount < 10) {
                printf(" %d. ", lineCount);
            }
            else {
                printf("%d. ", lineCount);
            }
        }
        else if(newCharacter == SPACE) {
            if(flag == 1) {
                wordCount++;
            }
            spaceCount++;
            flag = START;
        }
        else if(newCharacter == TAB) {
            if(flag == 1) {
                wordCount++;
            }
            tabCount++;
            flag = START;
        }
        else {
            characterCount++;
            flag = 1;
        }
        
        totalCharCount++;
    }
    
    printf("\n---\n");
    printf("Document Statistics\n");
    printf("      lol.c\n");
    printf("---");
    printf("\nLines           %d", lineCount);
    printf("\nWords           %d", ++    wordCount);
    printf("\nCharacters:");
    printf("\n   With spaces  %d", totalCharCount);
    printf("\n   No spaces    %d", characterCount);
    printf("\nSpaces          %d", spaceCount);
    printf("\nTabs            %d", tabCount);
    printf("\nBytes           %d\n", totalCharCount);
    printf("---\n");
    
    return 0;
}
