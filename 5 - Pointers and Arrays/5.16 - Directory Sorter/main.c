/*
	KnR - Exercise 5.16 | Directory Sorter
	___
	Add the -d ( "Directory option" ) which makes comparision only on letters, numbers and blanks.
	Make sure it works in conjunction with -f
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "macros.h"
#include "headers.h"
#include "globals.h"


int main( int argc, char *argv[] )
{
	option = 0;


    while( --argc > 0 && ( *++argv )[ 0 ] == '-' )
		getSortingFlags( &argc, argv );


    if( argc ) 
		printf( "Usage: sort -dfnr \n" );
    
	
	else if( ( nlines = readlines( lineptr, LINES ) ) > 0 ) {


		performSortingAsPerFlags();
		writelines( lineptr, nlines, option & DECR );
	}


	else {
		printf( "input too big to sort \n" );
		error = -1;
	}


    return error;
}
