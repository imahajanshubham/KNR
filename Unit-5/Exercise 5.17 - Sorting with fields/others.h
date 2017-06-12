	// Secondary Functions.


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include "globals.h"
# include "macros.h"


void writelines( char *lineptr[], int nlines )
{
    for( counter = 0; counter < nlines; counter++ )
        printf( "%s\n", lineptr[ counter ] );
}


void error( char *errMessage )
{
    printf( "%s\n", errMessage );
    exit( 1 );
}


int mgetline( char line_buffer[], int lim )
{
	fgets( line_buffer, MAXLEN, stdin );
	return strlen( line_buffer );
}


void swap( void *v[], int first, int second )
{
           temp = v[ first ];


     v[ first ] = v[ second ];
    v[ second ] = temp;
}


void quickSort( void *v[], int left, int right, int ( *comp )( void *, void * ) )
{ 
    if( left >= right )
        return;
    
    swap( v, left, ( left + right ) / 2 );
    last = left;
        

    for( counter = left + 1; counter <= right; counter++ )


        if( ( *comp )( v[ counter ], v[ left ] ) < 0 )
            swap( v, ++last, counter );


    swap( v, left, last );

    quickSort( v, left,   last - 1, comp );
    quickSort( v, last+1, right,    comp );
}


char *alloc( int n )
{
    if ( allocbuf + ALLOCSIZE - allocp >= n ) {
        allocp += n;
        return allocp - n;
    }
    

	return 0;
}


void afree( char *p )
{
    if( p >= allocbuf && p < allocbuf + ALLOCSIZE )
    allocp = p;
}


int readlines( char *lineptr[], int maxlines )
{
	nlines = 0;
    while( ( len = mgetline( line, MAXLEN ) ) > 1 )

		
		if( nlines >= maxlines || ( p = alloc( len ) ) == NULL )
            return -1;


        else {
            line[ len - 1 ] = '\0';
            strcpy( p, line );
            lineptr[ nlines++ ] = p;
        }


    return nlines;
}
