	// Macros.

#define MAXLINES 5000
#define MAXLEN 1000
#define OVERFLOW -1
#define MAXSTORAGE 5000


        // Variables.


int buff_Len, nlines;
char *lineptr[ MAXLINES ];
char line[ MAXLEN ], *buff_ptr;
char *linestop;
char bufferStorage[ MAXLINES ];
