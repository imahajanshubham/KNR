	// Functions.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "others.h"


int readlines( char *lineptr[], int maxlines )
{
	nlines = 0;


    while( ( len = mgetline( line ) ) > 2 )


        if( nlines >= maxlines || NO_FREE_MEMORY )
            return -1;


        else {
			line[ len - 1 ] = '\0';
			strcpy( p, line );
			lineptr[ nlines++ ] = p;
        }
   

   return nlines;
}


int charcmp( char *first_Item, char *second_Item )
{
    fold = ( option & FOLD ) ? 1 : 0;
     dir = ( option & MDIR ) ? 1 : 0;
    
    do
    {
        if( dir ) {
			while( GET_NEXT_ITEM( *first_Item  ) ); first_Item++;
			while( GET_NEXT_ITEM( *second_Item ) ); second_Item++;
        }


		EXTRACT( char_1,  first_Item  ); first_Item++;
		EXTRACT( char_2,  second_Item ); second_Item++;


    	if( char_1 == char_2 && char_1 == '\0' ) 
			return 0;


    } while( char_1 == char_2 );


    return char_1 - char_2;
}


int numcmp( char *first_Item, char *second_Item )
{
         if ( ITEM1 > ITEM2 ) return  1;
	else if ( ITEM1 < ITEM2 ) return -1;


    return 0;
}


void performSortingAsPerFlags()
{
	if( option & NUMERIC )
		quickSort( ( void ** )lineptr, 0, nlines - 1, ( int (*)( void *, void * ) )numcmp  );
     

	else
		quickSort( ( void ** )lineptr, 0, nlines - 1, ( int (*)( void *, void * ) )charcmp );
}


void getSortingFlags( int *argc, char *argv[] )
{

	while( ( choice = *++argv[ 0 ] ) )


		switch( choice )
		{
			case 'd': DIRECTORY_SORT; break; 
			case 'f': FOLDED_SORT;    break;
			
			
			case 'n': NUMBERIC_SORT;  break;
			case 'r': REVERSE_SORT;   break;
			
			
			default: printf( "sort: illegal option %c\n", choice );
				*argc =  1;
				error   = -1;
				break;
		}
}
