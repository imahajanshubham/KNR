	// Secondary functions.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "globals.h"
#include "macros.h"


void writelines( char *lineptr[], int nlines, int order )
{
    if (order) for( counter = nlines -1; counter >= 0; counter-- )
			printf( "%s\n", lineptr[ counter ] );
    
	
	else       for( counter = 0; counter < nlines; counter++ )
			printf( "%s\n", lineptr[ counter ] );
}


char *alloc( int n )
{
    if ( allocbuf + ALLOCSIZE - allocp >= n ) {
        allocp += n;
        return  allocp - n;
    }
    
	
	else return 0;
}


void afree( char *p )
{
    if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
        allocp = p;
}


int mgetline( char s[] )
{
	fgets( s, MAXLEN, stdin );
	return strlen( s );
}


void swap( void *lineBuffer[], int large, int small )
{
             tempBuffer = lineBuffer[ large ];


    lineBuffer[ large ] = lineBuffer[ small ];
	lineBuffer[ small ] = tempBuffer;
}


void quickSort( void *v[], int left, int right, int ( *comp ) ( void *, void * ) )
{
    allocp = allocbuf;
    if( left >= right ) return;


    swap( v, left, ( left + right ) / 2 );
    last = left;


    for( itemCount = left + 1; itemCount <= right; itemCount++ ) {


        if( ( *comp ) ( v[ itemCount ], v[ left ] ) < 0 )
            swap( v, ++last, itemCount );
	}


    swap( v, left, last );


    quickSort( v, left,     last - 1, comp );
    quickSort( v, last + 1, right,    comp );
}
