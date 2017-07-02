# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include "macros.h"
# include "globals.h"
# include "others.h"


int main( void ) {


    flag = 0;
    lineNo = bufp = 0, printf( "\n" );
    char word[ MAXWORD ];


    fptr = fopen( "data.txt", "r" );


    if( fptr == NULL ) {
        printf("Cannot open file!\n");
        exit( 0 );
    }

    
    while( fscanf( fptr, " %15s", word ) == 1 ) {

        
        if( isalpha( word[ 0 ] ) )


            if( ( searchIndex = binsearch( word, keytab ) ) >= 0 )
                keytab[ searchIndex ].count++;
    }


    fclose( fptr );


    for( keyCount = 0; keyCount < NKEYS; keyCount++ )
        
        
        if( keytab[ keyCount ].count > 0 )
            
            
            printf( "%d. Found %5s %d times.\n",
                ++lineNo,
                keytab[ keyCount ].word,
	            keytab[ keyCount ].count                
            );
    

    printf( "\n" );
    return 0;
}
