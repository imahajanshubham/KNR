/*
    Exercise 1.16
    _____
    Write a Program to print the longest line input.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"

// Macros.

#define MAXLINE 1000

void copy( char string1[],char string2[] )
{
    int iterator = 0;
    while( ( string1[ iterator ] = string2[ iterator++ ] ) != '\0' )
        ;
}

int getLineFromStdIn( char line[] )
{
    int iterator,newChar;

    for( iterator = 0; iterator < MAXLINE - 1 && ( newChar = getchar() ) != EOF && newChar != '\n'; iterator++ )
        line[ iterator ] = newChar;

    if( newChar == '\n' )
        line[ iterator++ ] = newChar;

    line[ iterator ] = '\0';
    return iterator;
}

int main( void )
{
    int len, max = 0;
    char line[ MAXLINE ], maxline[ MAXLINE ];

    while( ( len = getLineFromStdIn( line ) ) > 0 )
        if( len > max ) {
            max = len;
            copy( maxline, line );
        }

    if( max > 0 )
        printf( "%s", maxline );

    return 0;
}
