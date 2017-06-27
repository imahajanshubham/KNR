# include <stdio.h>
# include <ctype.h>
# include <string.h>


# include "keysStructure.c"
# include "./header_files/globals.h"
# include "/utilities/utility.c"
# include "/header_files/macros.h"
# include "/input_output/input_output.c"


int main( void ) {


    bufp = 0;


    while( myGetWord( word, MAXWORD ) != EOF ) 


        if( isalpha( word[ 0 ] ) ) 


            if( ( position = binsearch( word, keytab, NKEYS ) ) >= 0 )
                keytab[ position ].count++;


    for( position = 0; position < NKEYS; position++ )
        if( keytab[ position ].count > 0 )


    printf( "%4d %s\n", keytab[ position ].count, keytab[ position ].word );
    return 0;        
}
