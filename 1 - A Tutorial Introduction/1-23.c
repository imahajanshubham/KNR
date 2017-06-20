/*
REMOVE COMMENTS FROM SOURCE CODE FILE.

1. Run this Program.
2. It'll wait for you to enter a file name, Type the name of the file 
   in which you want to remove comments.
3. If there any Missplaced Comments, It'll notify you with Line Numbers and
   comments won't be removed till you fix the errors.
4. If everything goes OK, It'll create a new file 'untitled.c' (same directory) containing your un-commented code.

NOTE - Don't try removing errors in this file. 
       Why?
       Ex: if(newCharacter == '/')
           It'll treat this isolated '/' as missplaced comment.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 250   /*Maximum length of file-name.*/
#define START 0         /* Starting point of Line No.*/
#define READMODE "r"    /*Open the file in read-mode.*/
#define WRITEMODE "w"   /*Open the file in write-mode.*/
#define FOUND 0         /*Indicates missplaced comment.*/
#define NOTFOUND 1      /*Indicates no missplaced comments.*/
#define INSIDECMNT 2    /*Indicates that multi-line comment has started.*/
#define NULLCHAR '0'
#define WRITE 'w'
#define READ 'r'

void readFileForCommentError(char [], char);
void checkErrorInDoubleQuotes(int *, int *, FILE *);

void checkErrorInComments(int *, int *, FILE *);
void printErrorsIfAny(int, char [], int);

int main(void)
{
    char fileName[MAXLENGTH], mode = READ;
    system("clear");
    
    printf("ubuntu:~$ ");   scanf("%s", fileName);
    readFileForCommentError(fileName, mode);
    
    return 0;
}

void readFileForCommentError(char fileName[], char mode)
{
    int newCharacter, missplacedComment = NOTFOUND, lineNo = START;
    FILE *fptrR = fopen(fileName, READMODE);        /*Opening file containing commented code.*/
    FILE *fptrW = fopen("untitled.c", WRITEMODE);   /*Opening file which will containing un-commented code.*/
    
    while((newCharacter = fgetc(fptrR)) != EOF) {
    
        /*Checking whether there's missplaced multi-line comment or not.*/
        if(newCharacter == '*' && (newCharacter = fgetc(fptrR)) == '/') {
            missplacedComment = INSIDECMNT;          break;
        }
        else if(newCharacter == '/') {
        
            /*Checking whether there's single-line comment or not.*/
            if((newCharacter = fgetc(fptrR)) == '/') {
                while((newCharacter = fgetc(fptrR)) != '\n' && newCharacter != EOF)
                    ;
                if(mode == WRITE) {
                    fputc('\n', fptrW);
                    lineNo++;
                }
            }
            
            /*Checking if there's multi-line comment or not.*/
            else if(newCharacter == '*') {
                checkErrorInComments(&newCharacter, &missplacedComment, fptrR);
                if(missplacedComment == INSIDECMNT)   break;
            }
            
            /*Checking whether there's isolated '/' or not.*/
            else {
                missplacedComment = FOUND;            break;
            }
        }
        else {
            if(newCharacter == '\n')   lineNo++;
                   if(mode == WRITE)   fputc(newCharacter, fptrW);
        }
    }
    
      fclose(fptrR);   fclose(fptrW);
    if(mode == READ)   printErrorsIfAny(missplacedComment, fileName, lineNo);
}

void checkErrorInComments(int *newCharacter, int *missplacedComment, FILE *fptrR)
{
    *missplacedComment = INSIDECMNT;
    while((*newCharacter = fgetc(fptrR)) != EOF) {
    
        /*Checking whether the multi-line comment ends or not.*/
        if(*newCharacter == '*' && (*newCharacter = fgetc(fptrR)) == '/') {
            *missplacedComment = NOTFOUND;   break;
        }
    }
}

void printErrorsIfAny(int missplacedComment, char fileName[], int lineNo)
{
    switch(missplacedComment)
    {
        case FOUND       : printf("line %d: error: missplaced comment.\n", lineNo);              break;
        case NOTFOUND    : readFileForCommentError(fileName, WRITE);
                           printf("ubuntu:~$ success! visit 'untitled.c'.\n");                   break;
        case INSIDECMNT  : printf("line %d: error: missplaced multi-line comment.\n", lineNo);   break;
        default          : printf("fatal warning: program crashed, restart!");                   break;
    }
}
