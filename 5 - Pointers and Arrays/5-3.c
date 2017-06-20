/*
    Exercise 5.3
    _____
    Write a pointer version of the function strcat that we showed in 
    Chapter 2: strcat(s,t) copies the string t to the end of s.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"

// Macros.

#define MAXLEN 1000

void custom_strcat( char *string1, char *string2 )
{
    while( *( ++string1 ) != '\0' )
        ;
    string1--;

    while( ( *( string1++ ) = *( string2++ ) ) != '\0' )
        ;
}

int main( void )
{
    char string1[ MAXLEN ], string2[ MAXLEN ];

    printf("\nEva: Heyo <3\n     I'll copy a string to another :D\n     Let's get started, Enter first string.\n\nMe: ");
    fgets( string1, MAXLEN, stdin );

    printf("-----\nEva: Great job, now enter second string.\n\nMe: ");
    fgets( string2, MAXLEN, stdin );

    custom_strcat( string1, string2 );

    printf( "-----\nEva: I copied your string.\n     %s\n", string1 );

    return 0;
}
