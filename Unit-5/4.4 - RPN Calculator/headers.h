	// Functions.


#include "globals.h"
#include "ctype.h"
#include "macros.h"
#include "others.h"


void clearStack()
{
    stackptr = 0;
}


double pop()
{
    if( stackptr > 0 )
        return val[ --stackptr ];
    
    
    else {
        printf( "Error: Stack empty!\n" );
        return 0.0;
    }
}


void push( double operand )
{
    if( stackptr < MAXVAL )
        val[ stackptr++ ] = operand;
        
        
    else printf( "Error: Stack full, cant push %g.\n", operand );
}


void calcBufferIsEmpty()
{
	calcBuffer[charCount] = '\0';
	if( newChar != EOF )
		ungetch( newChar );
}


void getFractionalPart()
{
	while( isdigit( calcBuffer [ ++charCount ] = newChar = getch() ) )
		;
}


void getIntegerPart()
{
	while( isdigit( calcBuffer[ ++charCount ] = newChar = getch() ) )
		;
}


int negativeNumFound()
{
	if( newChar == '-' ) {
        
		if( isdigit( newChar = getch() ) || newChar == '.' )
            calcBuffer[ ++charCount ] = newChar;
            
            
        else {
            if( newChar != EOF ) 
            	ungetch( newChar );
            return '-';
        }
    }
    

    return 0;
}


int unknownCharFound()
{
	if( !isdigit( newChar ) && newChar !='.' && newChar !='-' ) 
		return newChar;
    	
    	
   	return 0;
}


void removeTrailingSpaces()
{
	while( ( calcBuffer[ 0 ] = newChar = getch() ) == ' ' || newChar =='\t' )
        ;
        
        
	calcBuffer[ 1 ] = '\0';
}


int getop()
{
	charCount = 0;
	removeTrailingSpaces();
    if( unknownCharFound() ) 
    	return newChar;
    

	if( negativeNumFound() )
		return '-';

    
    if( isdigit( newChar ) )
    	getIntegerPart();


    if(newChar=='.')
    	getFractionalPart();
    calcBufferIsEmpty();
    
	return NUMBER;
}
