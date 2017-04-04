/*
    Exercise 5.5
    _____
    Write versions of the library functions strncpy, strncat, and strncmp, which
    operate on at most the first n characters of their argument strings.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Macros.

#define MAXLEN 1000

// Global Variables.

int custom_strcmp( char *string1, char *string2 )
{
    while( *( string1++ ) != '\0' ) {
        if( *( string2++ ) == '\0' )
            return 1;
    }
    return ( string2 == '\0' ) ? 0: -1;
}

int checkStringOverflow( int strLen )
{
    return ( strLen == 1 ) ? 1 : 0;
}

void custom_strcat( char *string1, char *string2 ) {
    while( *( ++string1 ) != '\0' )
        ;
    string1--;

    while( ( *( string1++ ) = *( string2++ ) ) != '\0' )
        ;
}

void custom_strcpy( char *string1, char *string2 )
{
    int strLen = strlen( string1 );

    while( *string2 != '\0' && *string2 != '\n' ) {
        if( checkStringOverflow( strLen ) )
            break;
        *( string1++ ) = *( string2++ ), strLen--;
    }
}

void performOperations( char *string1, char *string2 )
{
    int choice;

    printf("\n-----Eva: 1. Copy | 2. Concatinate | 3. Compare the two strings | 4. Exit.\n\nMe: ");
    scanf( "%d", &choice );

    while( choice != 4 ) {
        switch( choice ) {
            case 1: 
                custom_strcpy( string1, string2 );
                printf("-----\nEva: Copied!\n     %s\n", string1);
                break;
            case 2:
                custom_strcat( string1, string2 );
                printf("-----\nEva: Concatinated!\n     %s\n", string1);
                break;
            case 3:
                printf( "-----\nEva: %d\n", custom_strcmp( string1, string2 ) );
                break;
            default:
                printf( "-----\nEva: Hey... I don't understand that!\n" );
                break;
        }
        printf("\n     1. Copy | 2. Concatinate | 3. Compare the two strings | 4. Exit.\n\nMe: ");
        scanf( "%d", &choice );
    }
}

int main(int argc, char *argv[])
{
    int choice;
    char string1[ MAXLEN ], string2[ MAXLEN ];

    printf("\nEva: Heyo <3\n     Enter two strings and see the bagic :D\n     Enter first string.\n\nMe: ");
    fgets( string1, MAXLEN, stdin );

    printf("-----\nEva: One more to go :p\n\nMe: ");
    fgets( string2, MAXLEN, stdin );

    performOperations( string1, string2 );
    printf( "\n" );

    return 0;
}
