        // Functions.


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "globals.h"


void cstmWriteLines( char *lineptr[], int nlines )
{
    int count = 0;
    while( count < nlines ) printf( "%s\n", lineptr[ count++ ] );
}


void swap( char *line_buffer[], int first, int second )
{
    char *temp_buffer;

    temp_buffer = line_buffer[ first];
    line_buffer[ first ] = line_buffer[ second ];
    line_buffer[ second ] = temp_buffer;
}


void quickSort( char *line_buffer[], int left, int right )
{
    int index, last;
    if( left >= right ) return;
    
    swap( line_buffer, left, ( left + right ) / 2 );
    last = left;

    for( index = left + 1; index <= right; index++ )
    
        if( strcmp( line_buffer[ index ], line_buffer[ left ] ) < 0 ) 
                swap( line_buffer, ++last, index );
        
    swap( line_buffer, left, last );
    quickSort( line_buffer, left, last - 1 );
    quickSort( line_buffer, last + 1, right );
}


int cstmGetLine( char *line_buffer )
{
    fgets( line_buffer, MAXLEN, stdin );
    return ( strlen( line_buffer ) );
}


int cstnReadLines( char *lineptr[], char *bufferStorage, int maxLines )
{
    buff_ptr = bufferStorage, nlines = 0;
    linestop = bufferStorage + MAXSTORAGE;

    while( ( buff_Len = cstmGetLine( line ) ) > 1 ) {
    
        if( nlines >= maxLines || ( buff_ptr + buff_Len > linestop ) )
                return OVERFLOW;
        
        else {
            line[ buff_Len - 1 ] = '\0';
            strcpy( buff_ptr, line );
            
            lineptr[ nlines++ ] = buff_ptr;
            buff_ptr += buff_Len;
		}
	}
	
    return nlines;
}
