# include <ctype.h>


# include "../header_files/globals.h"


/* ----- Custom getWord() ----- */


int myGetWord( char *word, int lim ) {


    wordPTR = word;
    while( isspace( newChar = getch() )) 
        ;


    if( newChar != EOF )
        *wordPTR++ = newChar;


    if( !isalpha( newChar ) ) {


        *wordPTR = '\0';
        return newChar;
    }


    for( ; --lim > 0; wordPTR++ )


        if( !isalnum( *wordPTR = getch() ) ) {
            ungetch( *wordPTR );
            break;
        }


    *wordPTR = '\0';
    return word[ 0 ];
}
