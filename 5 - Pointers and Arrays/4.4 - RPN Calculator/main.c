/*
	Exercise 4.4 - RPN Calculator
	___
	Add the commands to print the top elements of the stack without popping, to duplicate it,
	and to swap the top two elements. Add a command to clear the stack.

	Supports :	1. Element Duplication
				2. Element Swapping
				3. View Top Element
				4. Clear Stack.                        
*/


#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#include "headers.h"
#include "globals.h"
#include "macros.h"


int main()
{
	printf( "\n" );
	printHelp();
	charCount = bufp = stackptr = 0, flag = 1;
	
	
    while( ( operator = getop() ) != EOF )
    {
    	if( flag )
    		printf( "\nStack: " ), --flag;
        
        
        switch( operator )
        {
                case NUMBER:
                        push( atof( calcBuffer ) );
                        break;
                        
                        
                case '+':
                        push( pop() + pop() );
                        break;
                        
                        
                case '*':
                        push( pop() * pop() );
                        break;
                        
                        
                case '-':
                        op2 = pop();
                        push( pop() - op2 );
                        break;
                        
                        
                case '/':
                        op2 = pop();
                        if( op2 != 0.0 )
                            push( pop() / op2 );
                        
                        
                        else printf( "Error: Zero divisor!\n" );
                        break;
                        
                        
                case '%':
                        op2 = pop();
                        if( op2 != 0.0 )
                            push( fmod( pop(), op2 ) );
                            
                            
                        else printf( "Error: Zero divisor!\n" );
                        break;
                        
                        
                case TOP_ELEMENT:
                        op2 = pop();
                        printf( "\t%.8g\n", op2 );
                        push( op2 );
                        break;
                        
                        
                case CLEAR:
                        clearStack();
                        break;
                        
                        
                case DUPLICATE:
                        op2 = pop();
                        push( op2 );
                        push( op2 );
                        break;
                        
                        
                case SWAP:
                        op1 = pop();
                        op2 = pop();
                        push( op1 );
                        push( op2 );
                        break;  
                        
                        
                case '\n':
                        printf( "\t%.8g\n> ", pop() );
                        break;
                        
                        
                default:
                        printf( "Error: Unknown command %s.\n", calcBuffer );
                        break;
        }
    }
    
    
    printf( "\n" );
    return 0;
}
