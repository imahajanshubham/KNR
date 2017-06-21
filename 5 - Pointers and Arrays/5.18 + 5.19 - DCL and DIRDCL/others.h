# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "macros.h"
# include "globals.h"


//					| ----- Secondary Functions. ----- |


void errmsg( char *msg ) {


	printf( "%s", msg );
	prevtoken = YES;
}


int getch( void ) {


	return ( bufp > 0 ) ? buf[ --bufp ] : getchar();
}


void ungetch( int newChar ) {


	if ( bufp >= BUFSIZE )
		printf( "Ungetch: Too many characters.\n" );
 

	else buf[ bufp++ ] = newChar;
}
