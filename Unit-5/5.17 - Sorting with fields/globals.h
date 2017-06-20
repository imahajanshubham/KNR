	// Global Variables.


#include "macros.h"


int option,  len,     nlines, success;
int newChar, counter, first,  second;
int pos1,    last,    pos2,   index1;
int index2,  endpos,  fold,   dir;


char *lineptr[ LINES ],     *p,      line[ MAXLEN ];
char allocbuf[ ALLOCSIZE ], *allocp, firstChar;
char secondChar;


void *temp;
