#include "header_files.h"

FILE *fptrR, *fptrW;

int IfFile_AlreadyProcessed()
{
    if(flag == OFF) {
        printf("ubuntu:~$ success! visit 'untitled.c'.\n");
        flag = ON;
        return SUCCESS;
    }
    else return FAIL;
}

int printErrorsIfAny()
{
    switch(missplacedComment)
    {
        case FOUND       : printf("line %d: error: missplaced comment.\n", lineNo);              break;
        
        case NOTFOUND    : return IfFile_AlreadyProcessed();
                           break;
                           
        case INSIDECMNT  : printf("line %d: error: missplaced multi-line comment.\n", lineNo);   break;
        default          : printf("fatal warning: program crashed, restart!");                   break;
    }
    
    return FAIL;
}

void checkErrorInComments()
{
    missplacedComment = INSIDECMNT;
    while((newCharacter = fgetc(fptrR)) != EOF) {
        if(newCharacter == '*' && (newCharacter = fgetc(fptrR)) == '/') {
            missplacedComment = NOTFOUND;   break;
        }
    }
}

void check_Current_FileMode()
{
    if(mode == WRITE) {
        fputc('\n', fptrW);
        lineNo++;
    }
}

void singleLineCommentFound()
{
    while((newCharacter = fgetc(fptrR)) != '\n' && newCharacter != EOF)
        ;
}

int validateIfCommentFound()
{
    switch(newCharacter = fgetc(fptrR))
    {
        case '/':
            singleLineCommentFound();
            check_Current_FileMode();
            break;
            
        case '*':
            checkErrorInComments();
            if(missplacedComment == INSIDECMNT)
                return ERROR;
            break;
            
        default:
            missplacedComment = FOUND;
                return ERROR;
            break;
    }
    
    return NOTFOUND;
}

int checkForMissplacedComment()
{
    if((newCharacter = fgetc(fptrR)) == '/') {
        missplacedComment = INSIDECMNT;
        return ERROR;
    }
}

int processTheCharacter()
{
    switch(newCharacter)
    {
        case '*':
            if(checkForMissplacedComment() == ERROR)
                return ERROR;
            break;
        case '/':
            if(validateIfCommentFound() == ERROR)
                return ERROR;
            break;
        default:
            if(newCharacter == '\n')
                lineNo++;
            if(mode == WRITE)
                fputc(newCharacter, fptrW);
            break;
    }
    
    return NOTFOUND;
}

void readFileForCommentError()
{
    fptrR = fopen(fileName, READMODE), fptrW = fopen("untitled.c", WRITEMODE);
    
    while((newCharacter = fgetc(fptrR)) != EOF) {
        if(processTheCharacter() == ERROR)
            break;
    }
    
    fclose(fptrR), fclose(fptrW);
    if(mode == READ) {
        if(printErrorsIfAny() == SUCCESS)
            readFileForCommentError();
    }
}

int main(void)
{
    system("clear");
    
    printf("ubuntu:~$ ");   scanf("%s", fileName);
    readFileForCommentError();
    
    return 0;
}
