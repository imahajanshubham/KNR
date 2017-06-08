/*
	Exercise 5.7 - Readlines using array
	___
	1. Rewrite readlines to store lines in an array supplied by main,
	rather than calling alloc to maintain storage.
	
	2. How much faster is the program?

	NOTE - To stop program from taking inputs, presss ENTER two times.
*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "headers.h"
#include "globals.h"


int main( void )
{
	printf( "\n" );
	
    if( ( nlines = cstnReadLines( lineptr, bufferStorage, MAXLINES ) ) >= 0 ) {
    
        quickSort( lineptr, 0, nlines - 1 );
        cstmWriteLines( lineptr, nlines );
        
        printf( "\n" ); return 0;
    }
    else {
        printf(" error: input too big to sort\n\n" );
        return 1;
    }
}
