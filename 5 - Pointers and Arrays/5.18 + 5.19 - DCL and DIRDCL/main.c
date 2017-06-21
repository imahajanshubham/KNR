# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "macros.h"
# include "headers.h"
# include "globals.h"
# include "gettoken.h"


//										KNR - Exercise 5.18 + 5.19
//									  | ----- DCL and DIRDCL ----- |
//									  
//				1. Make dcl recover from input errors.
//				2. Modify undcl so that it does not add redundant parentheses to declarations.


int main() {


	printf("\n");
	bufp = 0, prevtoken = NO;


	while( gettoken() != EOF ) {


		strcpy( out, token );
		while( ( tokentype = gettoken() ) != '\n' )


			if( tokentype == PARENS || tokentype == BRACKETS )
				strcat( out, token );

			else if( tokentype == '*' ) {


				sprintf( tempBuffer, "(*%s)", out );
				strcpy( out, tempBuffer );
			}


			else if( tokentype == NAME ) {
				sprintf( tempBuffer, "%s %s", token, out );
				strcpy( out, tempBuffer );
			}


			else printf("Invalid input at %s\n", token );


		printf( "%s\n\n", out );
	}


	return 0;
}
