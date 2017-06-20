/*
	KnR - Exercise 5.17 | Sorting with fields
	_____
	Add a field handling capablity, so sorting may be done on the fields within lines, 
    each field sorted according to an independent set of options.
	
	
	NOTE: The index for the KnR Book was sorted with -df for the index category and -n for page number.
*/


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include "macros.h"
# include "headers.h"
# include "globals.h"


int main( int argc, char *argv[] )
{
	printf( "\n" );
   	success = option = pos1 = pos2 = 0;
	allocp = allocbuf;
    
	
	readargs( argc, argv );
    if( ( nlines = readlines( lineptr, LINES ) ) > 0 ) {
        
		
		if( option & NUMERIC )
             quickSort( ( void **) lineptr, 0, nlines - 1, ( int (*)( void *, void * ) )numcmp );
        
		
		else quickSort( ( void ** )lineptr, 0, nlines - 1, ( int (*)( void *, void * ) )charcmp );

        writelines( lineptr, nlines );
    }


    else {
        printf( "input too big to sort\n ");
        success = -1;
    }
    

	printf( "\n" );
    return success;
}















        










