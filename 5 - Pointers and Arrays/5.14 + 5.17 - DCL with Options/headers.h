# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include "globals.h"
# include "macros.h"


//                                 | ----- Primary Functions. ----- |


int numcmp( char *buffer1, char *buffer2 ) {


	double value1, value2;


	value1 = atof( buffer1 );
	value2 = atof( buffer2 );


	if( value1 < value2 )
		return -1;


	else if( value1 > value2 )
		return 1;


	else return 0;
}


int cstmSTRCMP( char *buffer1, char *buffer2 ) {


	if( directory ) {


		while( !isdigit( *buffer1 ) && !isalpha( *buffer1 ) && !isspace( *buffer1 ) && *buffer1 )
			++buffer1;


		while( !isdigit( *buffer2 ) && !isalpha( *buffer2 ) && !isspace( *buffer2 ) && *buffer2 )
			++buffer2;
	}


	while( fold ? ( tolower( *buffer1 ) == tolower( *buffer2 ) ) : ( *buffer1 == *buffer2 ) ) {


		if( *buffer1 == '\0' )
			return 0;


		++buffer1, ++buffer2;


		if( directory ) {


			while( !isdigit( *buffer1 ) && !isalpha( *buffer1 ) && !isspace( *buffer1 ) && *buffer1 )
				++buffer1;


			while( !isdigit( *buffer2 ) && !isalpha( *buffer2 ) && !isspace( *buffer2 ) && *buffer2 )
				++buffer2;
		}
	}


	return fold ? ( tolower( *buffer1 ) - tolower( *buffer2 ) ) : ( *buffer1 - *buffer2 );
}


int noValidFlagsFound( char *argv[] ) {


	for( argCount = 1; ( *argv )[ argCount ]; ++argCount )


		switch( ( *argv )[ argCount ] ) {


			case 'n':
				numeric = 1;
				break;


			case 'f':
				fold = 1;
				break;


			case 'r':
				decreasing = 1;
				break;


			case 'd':
				directory = 1;
				break;


			default:
				printf( "usage: sort -dfnr\n" );
				return 1;
		}


	return 0;
}
