/*
		              KnR - Exercise 2.1
	        	// --- Count the Ranges ----- //


	Write a program to determine the ranges of char, short, int, and long variables,
	both signed and unsigned, by printing appropriate values from standard headers and by direct computation.
	Harder if you compute them: determine the ranges of the various floating-point types.


	Also, do refer README.md :D
	Chears!
*/


# include <stdio.h>


int main( int argc, char **argv ) {

	
  printf( "\n" );


  printf( "Maximum | Signed,\n___\n" );
  printf( "\t1. Char  %d.\n" , ( ( unsigned char  ) ~ 0 >> 1 ) );
  printf( "\t2. Short %d.\n" , ( ( unsigned short ) ~ 0 >> 1 ) );
  printf( "\t3. Int   %d.\n" , ( ( unsigned int   ) ~ 0 >> 1 ) );
  printf( "\t4. Long  %ld.\n", ( ( unsigned long  ) ~ 0 >> 1 ) );


  printf( "\n" );

        
  printf( "Minimum | Signed,\n___\n" );
  printf( "\t1. Char  %d.\n" , - ( ( unsigned char  ) ~ 0 >> 1 ) - 1 );
  printf( "\t2. Short %d.\n" , - ( ( unsigned short ) ~ 0 >> 1 ) - 1 );
  printf( "\t3. Int   %d.\n" , - ( ( unsigned int   ) ~ 0 >> 1 ) - 1 );
  printf( "\t4. Long  %ld.\n", - ( ( unsigned long  ) ~ 0 >> 1 ) - 1 );


  printf( "\n" );


  printf( "Minimum | Unsigned,\n___\n" );
  printf( "\t1. Char  %d.\n" , ( unsigned char  ) ~ 0 );
  printf( "\t2. Short %d.\n" , ( unsigned short ) ~ 0 );
  printf( "\t3. Int   %u.\n" , ( unsigned int   ) ~ 0 );
  printf( "\t4. Long  %lu.\n", ( unsigned long  ) ~ 0 );


  printf( "\n" );
  return 0;
}
