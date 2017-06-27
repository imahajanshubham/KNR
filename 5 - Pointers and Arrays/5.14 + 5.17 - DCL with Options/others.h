# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "globals.h"
# include "macros.h"


//                                 | ----- Secondary Functions. ----- |


void writelines( char *lineptr[], int nlines ) {


	int lineNo = 1;


	while( nlines-- > 0 ) {


		printf( lineNo > 10 ? "%d. " : " %d. ", lineNo );
		lineNo++;
		printf( "%s\n", *lineptr++ );
	}


	printf( "\n" );
	return;
}


char *alloc( int n ) {


	if( allocbuf + ALLOCSIZE - allocp >= n ) {


		allocp += n;
		return allocp - n;
	}


	else return 0;
}


void swap( void *v[], int i, int j ) {


	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


int getLineFromUser( char *lineBuffer, int max ) {


	startingAddress = lineBuffer;


	while( --max && ( newChar = getchar() ) != EOF && newChar != '\n' )
		*lineBuffer++ = newChar;


	if( newChar == '\n' ) *lineBuffer++ = '\n';


	*lineBuffer = '\0';
	return lineBuffer - startingAddress;
}


void quicksort( void *v[], int left, int right, int ( *comp )( void*, void* ) ) {


	int last, i;
	void swap(void *v[], int, int);

	if( left >= right )
		return;


	swap( v, left, ( left + right ) / 2 );
	last = left;


	for( i = left + 1; i <= right; ++i )  {


		if( !decreasing ) {


			if(( *comp )( v[i], v[ left ] ) < 0 )
				swap(v, ++last, i);
		}


		else if( (* comp )( v[ i ], v[ left ] ) > 0 )
				swap( v, ++last, i );
	}


	swap( v, left, last );
	quicksort( v,     left, last - 1, comp );
	quicksort( v, last + 1,    right, comp );
}


int readlines( char *lineptr[], int maxlines ) {


	int len, nlines = 0;
	char *ptr, lineBuffer[ MAXLEN ];
	flag = 0;


	FILE *fptr;
    fptr = fopen( "data.txt", "r" );


    if( fptr == NULL ) {
        printf("Cannot open file!\n");
        exit(0);
    }


	while( fgets( lineBuffer, sizeof( lineBuffer ), fptr ) ) {


		len = strlen( lineBuffer );
		if( nlines >= maxlines || ( ptr = alloc( len ) ) == NULL )
			return -1;


		else if( lineBuffer[ len - 1 ] == '\n' ) {


			lineBuffer[ len - 1 ] = '\0';
			strcpy( ptr, lineBuffer );


			if( !flag )
				lineptr[ nlines++ ] = ptr;


			else flag = 0;
		}


		else {
			strcpy( ptr, lineBuffer );
			if( !flag ) {


				lineptr[ nlines++ ] = ptr;
				flag = 1;
			}
		}

	}


    fclose(fptr);
	return nlines;
}
