/*
KnR | 5.1
As written, getint treats a + or - not followed by a digit as a valid representation of zero.
Fix it to push such a character back on the input.
*/

#include "stdafx.h"
#include "ctype.h"
#include "stdio.h"

#define START 0
#define BUFFERSIZE 150

int buffer_pos = START;
char buffer[ BUFFERSIZE ];

void ungetch( int *new_char )
{
	if ( buffer_pos >= BUFFERSIZE )
		printf(" Error: Too many characters!\n" );

	else buffer[ buffer_pos++ ] = *new_char;
}

int getch( void )
{
	return ( buffer_pos > START ) ? buffer[ buffer_pos ] : getchar();
}

void checkIfStrayCharExistsInEnd( int *new_char )
{
	if ( *new_char != EOF )
		ungetch( new_char );
}

int checkIfCharNotANum( int *new_char )
{
	if ( !isdigit( *new_char ) && *new_char != EOF && *new_char != '+' && *new_char != '-' ) {
		ungetch( new_char );
		return 0;
	}
}

int checkIfNextCharIsANum( int *new_char, int *req_number )
{
	if ( !isdigit( *new_char ) ) {
		ungetch( new_char );
		return 0;
	}
	else {
		*req_number = 0;
		*req_number = ( *req_number ) * 10 + ( *new_char - '0' );
	}
}

void processAndStoreNumInStdIn( int *new_char, int *req_number )
{
	while ( isdigit( *new_char = getch() ) )
		*req_number = ( *req_number ) * 10 + ( *new_char - '0' );
}

int checkTheSignOfChar( int *new_char, int *req_number )
{
	if ( *new_char == '-' || *new_char == '+' ) {
		*new_char = getch();

		if ( !checkIfNextCharIsANum( new_char, req_number ) )
			return 0;
	}
}

void getSignMultiplierForNum( int *new_char, int *sign )
{
	*sign = ( *new_char == '-' ) ? -1 : 1;
}

void skipWhiteSpaceInStdIn( int *new_char )
{
	while ( isspace( *new_char = getch() ) )
		;
}

int getIntFromStdIn( int *req_number )
{
	int new_char, sign;

	skipWhiteSpaceInStdIn( &new_char );

	if ( !checkIfCharNotANum( &new_char) )
		return 0;

	getSignMultiplierForNum( &new_char, &sign );
	checkTheSignOfChar( &new_char, req_number );
	checkIfNextCharIsANum( &new_char, req_number );
	processAndStoreNumInStdIn( &new_char, req_number );

	*req_number *= sign;

	checkIfStrayCharExistsInEnd( &new_char );

	return new_char;
}

int main( void )
{
	int req_number;

	getIntFromStdIn( &req_number );

	printf( "Number: %d\n", req_number );

    return 0;
}