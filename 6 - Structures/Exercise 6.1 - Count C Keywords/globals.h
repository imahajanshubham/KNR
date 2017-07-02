# include <stdio.h>
# include "macros.h"


/* Global Variables. */


int bufp;
int searchIndex;
int keyCount;
int cond;
int lowerIndex;
int higherIndex;
int midPoint;
int newChar;
int lineNo;
int ch;


char buf[ BUFFSIZE ];


/* Function Declarations. */


int    getch( void );
void ungetch(  int );

char *ptr;
int flag;
FILE *fptr;
