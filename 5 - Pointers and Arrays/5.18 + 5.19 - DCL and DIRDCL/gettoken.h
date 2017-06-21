# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "globals.h"


//									| ----- The getToken Function. ----- |


void checkForValidAlphaNum( void ) {


	for( *ptr++ = nextToken; isalnum( nextToken = getch() ); ptr++ )
		*ptr = nextToken;


	*ptr = '\0';
	ungetch( nextToken );
	tokentype = NAME;
}


void checkForValidBrackets( void ) {


	for( *ptr++ = nextToken; ( *ptr = getch() ) != ']'; ptr++ )
            ;
	

	*ptr ='\0';
	strcat( token, "]" );
	tokentype = BRACKETS;
}


void checkForValidParenthesis( void ) {


	if( ( nextToken = getch() ) == ')' ) {


		strcpy( token,"()" );
		tokentype = PARENS;
	}


	else {
		ungetch( nextToken );
		tokentype = '(';
	}
}


void removeTrailingSpaces( void ) {


	while( ( nextToken =getch() ) == ' ' || nextToken == '\t' )
        ;
}


int prevTokenFound( void ) {


	if( prevtoken != YES )
		return 0;


	prevtoken = NO;
	return 1;
}


int gettoken( void ) {


    ptr = token;


	if( prevTokenFound() ) return tokentype;
    

	removeTrailingSpaces();


    if( nextToken == '(' )
		checkForValidParenthesis();


    else if( nextToken == '[' )
		checkForValidBrackets();


    else if( isalpha( nextToken ) )
		checkForValidAlphaNum();


    else tokentype = nextToken;


	return tokentype;
}
