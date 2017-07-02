# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include "headers.h"
# include "globals.h"
# include "macros.h"
# include "others.h"



//                                         Sorting with Options
//                                 | ----- Exercise 5.14 - 5.17. ----- |


int main( int argc, char *argv[] ) {


	allocp = allocbuf;
	decreasing = numeric = fold = directory = flag  = 0;
	printf( "\n" );


	while( --argc > 0 ) {


		++argv;
		if( ( *argv )[ 0 ] == '-' ) {
			if( noValidFlagsFound( argv ) ) return 1;
		}


		else {
			printf( "usage: sort -dfnr\n" );
			return 1;
		}
	}


	if( ( nlines = readlines( lineptr, MAXLINES ) ) >= 0 ) {


		if(numeric)
			quicksort( ( void** ) lineptr, 0, nlines - 1,
		              ( int ( * )( void*, void* ) )numcmp );


		else
			quicksort( ( void** ) lineptr, 0, nlines - 1,
		              ( int ( * )( void*, void* ) )cstmSTRCMP );


		writelines( lineptr, nlines );
		return 0;
	}


	else printf( "input too big to sort\n" );


	printf("\n\n");
}
