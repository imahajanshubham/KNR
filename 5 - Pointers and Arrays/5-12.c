/*
    Exercise 5.12
    _____
    Extend entab and detab to accept the shorthand.
*/

// Header Files.

#include "stdio.h"
#include "stdlib.h"

// Macros.

#define MAXLEN 50
#define TABSIZE  8
#define YES 1
#define NO  0

// Global Variables.

int blanksCount, tabCount, buffLen;
blanksCount = tabCount = buffLen = 0;

int i, inc, pos, newChar, colIndex;
char inputBuffer[ MAXLEN ];

int tabpos()
{
    return ( pos > MAXLEN ) ? YES : inputBuffer[ pos ];
}

void checkIfTabIsFound()
{
    if( newChar == '\n' )
        pos = 0;
    else if( newChar == '\t' ) {
        while( tabpos() != YES )
            ++pos;
    }
}

void printRemainingBlanks()
{
    if( newChar == '\t' )
        blanksCount = 0;
    else while( blanksCount-- > 0 )
        putchar( ' ' );
    putchar( newChar );
}

void printTabsFound()
{
    while( tabCount-- > 0 )
        putchar( '\t' );
}

void checkIfBlanksEqualsTab()
{
    if( tabpos() == NO )
        ++blanksCount;
    else blanksCount = 0, ++tabCount;
}

void entab()
{
    for( pos = 1; ( newChar = getchar() ) != EOF; pos++ )
        if( newChar == ' ' )
            checkIfBlanksEqualsTab();
        else {
            printTabsFound();
            printRemainingBlanks();
            checkIfTabIsFound();
        }
}

void setCustomTabStops( int argc, char *argv[] )
{
    while( --argc > 0 ) {
        pos = atoi( *++argv );
        if( pos > 0 && pos <= MAXLEN )
            inputBuffer[ pos ] = YES;
    }
}

void resetTabStops()
{
    for( colIndex = 1; colIndex <= buffLen; colIndex++ )
        inputBuffer[ colIndex ] = NO;
}

void setRangedTabStops()
{
    for( colIndex = 1; colIndex <= MAXLEN; colIndex++ ) {
        if( colIndex != pos )
            inputBuffer[ colIndex ] = NO;
        else inputBuffer[ colIndex ] = YES, pos += inc;
    }
}

void setDefaultTabStops()
{
    for( colIndex = 1; colIndex <= MAXLEN; colIndex++ )
            inputBuffer[ colIndex ] = ( colIndex % TABSIZE == 0 ) ? YES : NO;
}

void setTabStops( int argc, char *argv[] )
{
    if( argc <= 1 )
        setDefaultTabStops();
    else if( argc == 3 && *argv[ 1 ] == '-' && *argv[ 2 ] == '+' ) {
        pos = atoi( &( *++argv )[ 1 ] );
        inc = atoi( &( *++argv )[ 1 ] );
        setRangedTabStops();
    }
    else {
        resetTabStops();
        setCustomTabStops( argc, argv );
    }
}

int main( int argc, char *argv[] )
{
    setTabStops( argc, argv );
    entab();

    return 0;
}
