# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "macros.h"
# include "globals.h"
# include "others.h"


//					| ----- Primary Functions. ----- |


void dcl( void ) {
   

	for( ptrCount = 0; gettoken() == '*'; ptrCount++ )
		;


	dirdcl();

	
	while( ptrCount-- > 0 )
		strcat( out, "pointer to" );
}


void checkForValidParen( void ) {


	dcl();
	if( tokentype != ')' )
		errmsg( "Error: Missing )\n" );
}


void dirdcl( void ) {


	if( tokentype == '(' )
		checkForValidParen();


	else if( tokentype == NAME )
		strcpy( name, token );


	else errmsg( "Error: Expected name or (dcl)\n" );


	while( ( tokentype = gettoken() ) == PARENS || tokentype == BRACKETS )


		if( tokentype == PARENS )
			strcat( out, "function returning" );


		else {
			strcat( out, "array" );
			strcat( out, token   );
			strcat( out, "of"    );
		}
}
