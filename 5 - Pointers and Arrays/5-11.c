/*
	Exercise 5.11
	____
	Extend entab and detab to accept the shorthand entab -m +n to mean tab stops every n columns;
	starting at column m. choose a convenient (for the user) default behaviour.
*/

// Header Files.

#include "stdio.h"
#include "math.h"

// Macros.

#define MAXLEN 50
#define TABSIZE  8
#define YES 1
#define NO  0

// Global Variables.

int colIndex, inc, pos, newChar, buffLen = 0;
char inputBuffer[ MAXLEN ];

int tabpos()
{
	return ( pos > MAXLEN ) ? YES : inputBuffer[ pos ];
}

void replaceTabWithSpaces()
{
	do putchar(' '), pos++;
	while( tabpos() != YES );
}

void detab()
{   
	pos = 1;
    while( ( newChar = getchar() ) != EOF ) {
    	buffLen++;
    	switch( newChar ) {
    		case '\t': replaceTabWithSpaces(); break;
    		case '\n': putchar( newChar ); pos = 1 ; break;
    		default: putchar( newChar ); ++pos; break;
    	}
    }
}

void resetTabStops()
{
	for( colIndex = 1; colIndex <= buffLen; colIndex++ )
		inputBuffer[ colIndex ] = NO;
}

void setCustomTabStops( int argc, char *argv[] )
{
	while( --argc < 0 ) {
		pos = atoi( *++argv );
		if( pos > 0 && pos <= MAXLEN )
			inputBuffer[ pos ] = YES;
	}
}

void setRangedTabStops()
{
	for( colIndex = 1; colIndex <= MAXLEN; colIndex++ ) {
		if( colIndex != pos )
			inputBuffer[ colIndex ] = NO;

		else inputBuffer[ colIndex ] = YES, pos += inc;
	}
}

void setDefaultTabStops()
{
	for( colIndex = 1; colIndex <= MAXLEN; colIndex++ )
        	inputBuffer[ colIndex ] = ( colIndex % TABSIZE == 0 ) ? YES : NO;
}

void setTabStops( int argc, char *argv[] )
{
    if( argc <= 1 )
        setDefaultTabStops();
    else if( argc == 3 && *argv[ 1 ] == '-' && *argv[ 2 ] == '+' ) {
        pos = atoi( &( *++argv )[ 1 ] );
        inc = atoi( &( *++argv )[ 1 ] );
        setRangedTabStops();
    }
    else {
    	resetTabStops();
    	setCustomTabStops( argc, argv );
    }
}

int main( int argc, char *argv[] )
{
    setTabStops( argc, argv );
    detab();

    return 0;
}
