# include <stdio.h>
# include <string.h>


# include "../header_files/globals.h"
# include "../header_files/macros.h"
# include "../keysStructure.c"


/* ----- Utility Functions. ----- */


void ungetch( int nextChar ) {


    if( bufp >= BUFSIZE )
        printf( "ungetch: too many characters.\n" );


    else buf[ bufp++ ] = nextChar;
}


int getch( void ) {


    return( bufp > 0 ) ? buf[ --bufp ] : getchar();
}


int binsearch( char *word, struct key tab[], int keyCount ) {


    lowerKey = 0;
    higherKey = keyCount - 1;


    while( lowerKey <= higherKey ) {


        middleKey = ( lowerKey + higherKey ) / 2;
        if( ( cond = strcmp( word, tab[ middleKey ].word ) ) < 0 )
            higherKey = middleKey - 1;


        else if( cond > 0 )
            lowerKey = middleKey + 1;


        else return middleKey;
    }


    return -1;
}
