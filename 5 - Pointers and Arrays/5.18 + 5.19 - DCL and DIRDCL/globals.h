# include "macros.h"


//						| ----- Global Variables. ----- |


int prevtoken;
int ptrCount;
int tokentype;
int bufp;
int nextToken;


char *ptr;
char tempBuffer[    MAXLEN ];
char      token[ TOKENSIZE ];
char       name[    MAXLEN ];
char        out[    MAXLEN ];
char        buf[   BUFSIZE ];


//						| ----- Function Declarations. ----- |


int prevTokenFound( void );
int       gettoken( void );
int          getch( void );


void     removeTrailingSpaces(   void );
void checkForValidParenthesis(   void );
void    checkForValidBrackets(   void );
void    checkForValidAlphaNum(   void );
void                   dirdcl(   void );
void                   errmsg( char * );
void                  ungetch(    int );
void                      dcl(   void );
