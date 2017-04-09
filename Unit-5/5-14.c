
/*
    Exercise 5.14
    _____
    Modify the sort program to handle a -r flag, which indicates sorting in
    reverse (decreasing) order. Be sure that -r works with -n.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Macros.

#define MAXLINES 1000
#define TRUE 1
#define FALSE 0
#define MAXLEN 1000

// Global Variables.

int iterator, reverse = FALSE, len;
char *linePtr, line[ MAXLEN ], lineCount;
char numeric = FALSE, *lineptr[ MAXLINES ];

void writelines( char *lineptr[], int lineCount )
{
    for( iterator = 0; iterator < lineCount; iterator++ )
        printf( "     %d. %s\n", iterator + 1, lineptr[ iterator ] );
}

int getALine()
{
    int newChar;
    for( iterator = 0; iterator < MAXLEN - 1 && ( newChar = getchar() ) != EOF && newChar != '\n'; iterator++ )
        line[ iterator ] = newChar;

    if( newChar == '\n' )
        line[ iterator++ ] = newChar;

    line[ iterator ] = '\0';
    return iterator;
}

void deleteEmptyLine()
{
    line[ len - 1 ] = '\0';
    strcpy( linePtr, line );
}

void printLineNo()
{
    printf( "    %d. ", lineCount + 1 );
}

int readlines()
{
    lineCount = 0;

    while( ( len = getALine() ) > 0 ) {
        if( lineCount >= MAXLEN || ( linePtr = malloc( len ) ) == NULL )
            return -1;
        else {
            deleteEmptyLine();
            lineptr[ lineCount++ ] = linePtr;
        }

        printLineNo();
    }
    return lineCount;
}

int pstrcmp( const void *prevPtr, const void *nxtPtr )
{
  char * const *prevString = reverse ? nxtPtr : prevPtr;
  char * const *nxtString = reverse ? prevPtr : nxtPtr;

  return strcmp( *prevString, *nxtString );
}

int numcmp( const void *prevPtr, const void *nxtPtr )
{
    char * const *prevString = reverse ? nxtPtr : prevPtr;
    char * const *nxtString = reverse ? prevPtr : nxtPtr;
    double prevNo, nxtNo;

    prevNo = atof( *prevString );
    nxtNo = atof( *nxtString );

    if( prevNo < nxtNo )
        return -1;
    else if( prevNo > nxtNo )                                     
        return 1;      
    else return 0;
}

void checkIfFlagsPresent( char *argv[], int iterator )
{
    if( *argv[ iterator ] == '-' )
        switch( *( argv[ iterator ] + 1 ) ) {
            case 'n':  numeric = TRUE;  break;
            case 'r':  reverse = TRUE;  break;
            default :  printf( "---\nEva: I don't understand this option :(\n" );
        }
}

void processIfCmdArgPresent( int argc, char *argv[] )
{
    for( iterator = 1; iterator < argc; iterator++ )
        checkIfFlagsPresent( argv, iterator );
}

int main( int argc, char *argv[] )
{
    processIfCmdArgPresent( argc, argv );
    printf( "Eva: Heyo <3\n     I'll sort the elements :D\n     Read?... Set... Enter the no's.\n\nMe: " );

    if( ( lineCount = readlines() ) >= 0 ) {
        qsort( lineptr, lineCount, sizeof( *lineptr ), numeric ? numcmp : pstrcmp );

        printf( "\n---\nEva: Here's your sorted no's in \n" );
        printf( ( reverse == TRUE ) ? "Reverse Order :)\n": "Default Order :D\n" ); 
        writelines( lineptr, lineCount );
    }
    else printf( "---\nEva: Ah snaps, An error occured!\n" );

    return 0;
}
