#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define START 0
#define MAXVAL 100
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(void)
{
    int input;
    double op2;
    char inputString[MAXOP];
    system("clear");
    
    while ((input = getop(inputString)) != EOF) {
        switch (input) {
            case NUMBER: push(atof(inputString));                     break;
            case '+'   : push(pop() + pop());                         break;
            case '*'   : push(pop() * pop());                         break;
            case '-'   : op2 = pop();   push(pop() - op2);            break; 
            case '/'   : op2 = pop();
                         if (op2 != 0.0) {
                             push(pop() / op2);
                         }
                         else {
                             printf("error: zero divisor\n");
                         }
                         break;
            case '%'   :
                         op2 = pop();
                         if(op2 != 0.0) {
                             push(fmod(pop(), op2));
                         }
                         else {
                             printf("erro: zero divisor\n");
                         }
                         break;
            case '\n'  : printf("ubuntu:~$ %.8g\n", pop());          break;
            default    : printf("error: unknown command %s inputString\n", inputString);   
                         break;
        }
    }
    
    return 0;
}

int sp = 0;
double valueArray[MAXVAL];

void push(double value)
{
    if(sp < MAXVAL)
        valueArray[sp++]=value;
    else
        printf("error: stack full, cant push %f value\n",value);
}

double pop(void)
{
    if(sp>0)
        return valueArray[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char inputString[])
{
    int iterator, newCharacter;

    while((inputString[0] = newCharacter = getch()) == ' ' || newCharacter =='\t')
        ;
        
    inputString[1] = '\0';
    
    iterator = START;
    if(!isdigit(newCharacter) && newCharacter!='.' && newCharacter!='-') {
        return newCharacter;
    }

    if(newCharacter=='-') {
        if(isdigit(newCharacter=getch()) || newCharacter == '.') {
            inputString[++iterator]=newCharacter;
        }
        else {
            if(newCharacter!=EOF) {
                ungetch(newCharacter);
            }
            return '-';
        }
    }
    
    if(isdigit(newCharacter)) {
        while(isdigit(inputString[++iterator] =newCharacter = getch()))
            ;
    }
        
    if(newCharacter=='.') {
        while(isdigit(inputString[++iterator] = newCharacter = getch()))
            ;
    }
        
    inputString[iterator] = '\0';
    if(newCharacter!=EOF) {
        ungetch(newCharacter);
    }
    
    return NUMBER;
}

char inputBuffer[BUFSIZE];
int bufferIndex = START;

int getch(void)
{
    return (bufferIndex > 0) ? inputBuffer[--bufferIndex] : getchar();
}

void ungetch(int newCharacter)
{
    if(bufferIndex >= BUFSIZE)
        printf("overflow: too many characters\n");
    else
        inputBuffer[bufferIndex++] = newCharacter;
}

