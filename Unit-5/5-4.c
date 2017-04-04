/*
    Exercise 5.4
    _____
    Write the function strend(s,t), which returns 1 
    if the string t occurs at the end of the string s,and zero otherwise.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Macros.

#define MAXLEN 1000

// Global Variables.
int strLen;

int custom_strend( char *string1, char *string2 )
{
    strLen = strlen( string2 );

    while( *string1 != '\0' )
        ++string1;
    while( *string2!= '\0' )
        ++string2;
            
    --string1, --string2;
    while( strLen > 0 )
    {
        if( *( string2-- ) == *( string1-- ) )
            --strLen;
        else return 0;
    }

    if( strLen == 0)
        return 1;
}

int main( void )
{
    char string1[ MAXLEN ], string2[ MAXLEN ];

    printf( "\nEva: Heyo <3\n     I'll let ya know if a string occurs at end of another or not :D\n" );

    printf( "     Ready? Enter first string.\n\nMe: " );
    fgets( string1, MAXLEN, stdin );

    printf( "     Ready? Enter first string.\n\nMe: " );
    fgets( string2, MAXLEN, stdin );

    printf( "-----\nEva: " );
    custom_strend( string1, string2 ) == 1 ? printf( "String is in the end :D\n" ) : printf( "I couldn't find the string in the end :(\n" );

    return 0;
}
