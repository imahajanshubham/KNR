# include "macros.h"


//                                 | ----- Global Variables. ----- |


char  *lineptr[ MAXLINES ];
char allocbuf[ ALLOCSIZE ];
char     *startingAddress;
char              *allocp;


int    newChar;
int decreasing;
int    numeric;
int       fold;
int  directory;
int   argCount;
int       flag;
int     nlines;


//                                 | ----- Function Declarations. ----- |


char *alloc( int );


int noValidFlagsFound( char *argv[] );
int  getLineFromUser(  char*,   int );
int        readlines( char**,   int );
int           numcmp(  char*, char* );
int       cstmSTRCMP(  char*, char* );


void writelines( char**, int );
void  quicksort( void**, int, int, int ( * )( void*, void* ) );
