# include "macros.h"


/* ----- Global Variables. ----- */


char buf [ BUFSIZE ];
char word[ MAXWORD ];
char *wordPTR;


int  bufp;
int  position;
int  newChar; 
int  cond;
int  lowerKey;
int  higherKey;
int  middleKey;


/* ----- Function Declarations. ----- */


int  myGetWord( char *, int );
int  binsearch( char *, struct key *, int );
int  getch    ( void );
void ungetch  ( int  );
