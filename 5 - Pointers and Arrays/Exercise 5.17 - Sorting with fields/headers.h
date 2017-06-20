	// Primary Functions.


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include "others.h"


void substr( char *line_buffer, char *str )
{
    len = strlen( line_buffer );
        

    if( pos2 > 0 && len > pos2 )
        len = pos2;


    else if ( pos2 > 0 && len < pos2 )
        error( "substr: string too short" );


    for( first = 0, second = pos1; second < len; second++, first++ )
        str[ first ] = str[ second ];


    str[ first ] = '\0';
}


void getTheFoldedChar( char *firstString, char *secondString )
{
	firstChar =  fold ? tolower(  firstString[ index1 ] ) :  firstString[ index1 ];
    index1++;


	secondChar = fold ? tolower( secondString[ index2 ] ) : secondString[ index2 ];
    index2++;
}


void getNextQuerryToSort( char *firstString, char *secondString )
{
	while( index1 < endpos && !isalnum( firstString[ index1 ] )
		&& firstString[ index1 ] != ' ' && firstString[ index1 ] !='\0' )
			;
		index1++;


	while( index2 < endpos && !isalnum( secondString[ index2 ] )
		&& secondString[ index2 ] != ' ' && secondString[ index2 ] != '\0' )
			;
		index2++;
}


void setFlags()
{
	fold = ( option & FOLD ) ? 1 : 0;
    dir  = ( option & MDIR ) ? 1 : 0;
    index1 = index2 = 0;
}


int charcmp( char *firstString, char *secondString )
{
	setFlags();
    if( pos2 > 0 ) endpos = pos2;


    else if( ( endpos = strlen( firstString ) ) > strlen( secondString ) )
        endpos = strlen( secondString );

    do
    {
        if( dir ) getNextQuerryToSort( firstString, secondString );
   

		if( index1 < endpos && index2 < endpos ) {


			getTheFoldedChar( firstString, secondString );
			if( firstChar == secondChar && firstChar == '\0' )
                return 0;
        }


    }while( firstChar == secondChar && index1 < endpos && index2 < endpos );


    return firstChar - secondChar;
}


int numcmp( char *s1, char *s2 )
{
    double string1, string2;
    char str[ MAXSTR ];

    substr( s1, str );
    string1 = atof( str );

    substr( s2, str );
    string2 = atof( str );

         if( string1 < string2 ) return -1;
    else if( string1 > string2 ) return  1;


	return 0;
}


void extractFlagsFromCommandArgs( char *argv[] )
{
	while( ( newChar = *( ++argv[ 0 ] ) ) )
		
		
		switch( newChar )
		{
			case 'd':
				option |= MDIR;
				break;
			
			
			case 'f':
				option |= FOLD;
				break;
			
			
			case 'n':
				option |= NUMERIC;
				break;
			
			
			case 'r':
				option |= DECR;
				break;
			
			
			default:
				error( "Usage: sort error" );
				break;
		}
}


void readargs( int argc, char *argv[] )
{
	while( --argc > 0 && ( ( newChar = ( *++argv )[ 0 ] ) == '-' || ( newChar == '+' ) ) ) {


        if( newChar == '-' && !isdigit( *( argv[ 0 ] + 1) ) )
			extractFlagsFromCommandArgs( argv );


		else if( newChar == '-' )
            pos2 = atoi( argv[ 0 ] + 1 );


        else if( ( pos1 = atoi( argv[ 0 ] + 1 ) ) < 0 )
            error( "Usage: sort error" );
    }


    if( argc || pos1 > pos2 )
        error( "Usage: sort error" );
}
