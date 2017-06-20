/*
KnR | 5.2 (double TYPE)
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

void combineDecimal_IntNum(double *req_number, double *decimal_num, int *power_multiplier ) {
	*req_number += ( *decimal_num / *power_multiplier );
}

void getDecimalNumber( int *new_char, double *decimal_num , int *power_multiplier ) {

	while ( isdigit( *new_char = getch() ) ) {
		*decimal_num = (*decimal_num) * 10 + (*new_char - '0');
	
		*power_multiplier *= 10;
	}
}

int checkIfThereIsADecimal( int *new_char ) {
	if ( *new_char == '.' )
		return 0;
}

void getIntegerNumber( int *new_char, double *req_number )
{
	while (isdigit(*new_char = getch()))
		*req_number = ( *req_number ) * 10 + ( *new_char - '0' );
}

int checkIfCharNotANum( int *new_char )
{
	if ( !isdigit( *new_char ) && *new_char != EOF && *new_char != '+' && *new_char != '-' ) {
		
		ungetch( new_char );

		return 0;
	}
}

int checkIfNextCharIsANum( int *new_char, double *req_number )
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

int checkTheSignOfChar( int *new_char, double *req_number )
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

int getIntFromStdIn( double *req_number )
{
	double decimal_num = 0.0;
	int new_char, sign, power_multiplier = 1;

	skipWhiteSpaceInStdIn( &new_char );

	if ( !checkIfCharNotANum( &new_char) )
		return 0;

	getSignMultiplierForNum( &new_char, &sign );
	checkTheSignOfChar( &new_char, req_number );

	checkIfNextCharIsANum( &new_char, req_number );
	getIntegerNumber( &new_char, req_number );

	if (checkIfThereIsADecimal(&new_char)) {
		*req_number *= sign;
		return -4;
	}

	getDecimalNumber( &new_char, &decimal_num , &power_multiplier );
	combineDecimal_IntNum( req_number, &decimal_num , &power_multiplier );

	*req_number *= sign;

	checkIfStrayCharExistsInEnd( &new_char );

	return new_char;
}

int main( void )
{
	double req_number = 0.0;

	getIntFromStdIn( &req_number );

	printf( "Number: %lf\n", req_number );

    return 0;
}
