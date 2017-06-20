	// Secondary Functions.


#include "stdio.h"
#include "globals.h"
#include "macros.h"


void ungetch( int buffChar )
{
    if( bufp >= BUFSIZE )
        printf( "Ungetch: Too many characters!\n" );
        
        
    else buf[ bufp++ ] = buffChar;
}


int getch()
{
    return ( bufp > 0 ) ? buf[ --bufp ] : getchar();
}


void printHelp()
{
	printf( "d - Dublicate the element.    |    s - Swaps the two elements.\n" );
	printf( "c - Clears the stack.         |    ? - Go to top stack-element.\n\n" );
	
	
	printf( "Example: 1 d +  3 s ?\n\n___\nBuffer: " );
}
