/*
    Exercise 5.13
    _____
    Write a Program tail, which prints the lastLine n MAXLINES of its input. By default n is 10
    let us say; but it can be changed by an optional argument so that tail -n.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Macros.

#define MAXLINES   100
#define MAXLEN  100
#define DEFAULT 10

// Global Variables.

int first, strIndex, lastLine, len, lastNLines, lineCount;
char line[ MAXLEN ], *lineptr[ MAXLINES ];
char *bufPointer, *buffer, *bufend;


void printLastNLines()
{
    printf( "\n-----\nEva: Here are your last n lines...\n\n" );

    for( strIndex = first; lastNLines-- > 0;strIndex = ( strIndex + 1 ) % MAXLINES )
        printf( "     %d. %s", strIndex + 1, lineptr[ strIndex ] );
    printf( "\n" );
}

void updateVariables()
{
    if( lastNLines > lineCount )
        lastNLines = lineCount;

    first = lastLine - lastNLines;

    if( first < 0 )
        first += MAXLINES;
}

void storeLastNLines()
{
    lineptr[ lastLine ] = bufPointer;

    strcpy( lineptr[ lastLine ], line );
    
    if( ++lastLine >= MAXLINES )
        lastLine = 0;

    bufPointer += len + 1;
    lineCount++;
}

int getLine( char string[], int lim )
{
    int newChar, strIndex = 0;

    if( lineCount <  9 ) printf( " %d. ", lineCount + 1 );
    else printf( " %d. ", lineCount + 1 );

    while( strIndex < lim - 1 && ( newChar = getchar() ) != EOF && newChar != '\n' )
        string[ strIndex++ ] = newChar;

    if( newChar == '\n' )
        string[ strIndex++ ] = newChar;
    string[ strIndex ] = '\0';

    return strIndex;
}

void getLinesFromUser()
{
    lastLine = lineCount = 0;

    while( ( len = getLine( line, MAXLEN ) ) > 0 ) {
        if( bufPointer + len + 1 >= bufend )
            bufPointer = buffer;
        storeLastNLines();
        printf( "    " );
    }

    updateVariables();
}

void checkBufferOverflow()
{
    if(( bufPointer = buffer = malloc( MAXLINES * MAXLEN ) ) == NULL )
        printf( "Eva: Oh snaps! I ran into a problem!\n" );
    bufend = buffer + MAXLINES + MAXLEN;
}

void resetLinePointerArray()
{
    for( strIndex = 0; strIndex < MAXLINES; strIndex++ )
            lineptr[ strIndex ] = NULL;
}

void validateLastNLinesCount()
{
    if( lastNLines < 1 || lastNLines > MAXLINES )
        lastNLines = MAXLINES;
}

void getLastNLinesCount( int argc, char *argv[] )
{
    if( argc == 1 )
        lastNLines = DEFAULT;
    else if( argc == 2 && ( *++argv )[ 0 ] == '-' )
        lastNLines = atoi( argv[ 0 ] + 1 );
    else printf( "Eva: Oh snaps! I ran into a problem!\n" ), exit( 1 );
}

int main( int argc, char *argv[] )
{
    printf( "\nEva: Heyo <3\n     I'll print lastLine 'n' lines entered by you :D\n" );

    getLastNLinesCount( argc, argv );
    validateLastNLinesCount();

    resetLinePointerArray();
    checkBufferOverflow();

    printf( "\nMe: " );
    getLinesFromUser();

    storeLastNLines();
    printLastNLines();

    return 0;
}
