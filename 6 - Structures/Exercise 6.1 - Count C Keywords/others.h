# include <string.h>
# include <stdio.h>
# include "globals.h"
# include "structures.h"
# include "macros.h"


/* Secondary Functions. */


int binsearch( char *word, struct key tab[] ) {
      

    lowerIndex = 0;
    higherIndex = NKEYS - 1;
    
    
    while( lowerIndex <= higherIndex ) {


        midPoint = ( lowerIndex + higherIndex ) / 2;
        if( ( cond = strcmp( word, tab[ midPoint ].word ) ) < 0 )
	        higherIndex = midPoint - 1;
        
        
        else if( cond > 0 )
	        lowerIndex = midPoint + 1;
      
        
        else return midPoint;
    }
    
    
    return -1;
}


int getch( void ) {


    return ( bufp > 0 ) ? buf[ --bufp ] : getchar();
}


void ungetch( int newChar ) {
  
    
    if( bufp >= BUFFSIZE )
        printf( "UNGETCH: Too many characters.\n" );
 
    
    else buf[ bufp++ ] = newChar;
}
