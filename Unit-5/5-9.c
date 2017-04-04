#include "stdio.h"
#include "stdlib.h"

int days_till_date;

static char days_in_month [ 2 ] [ 13 ] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

void checkLeapYear ( int *leap, int year )
{
	*leap = ( year % 4 == 0 ) && ( year % 100 != 0 ) || ( year % 400 == 0 );
}

void convertYearToMonthnDay ( int yearday, int year )
{
	int month_index,leap;

	checkLeapYear ( &leap, year );

	for ( month_index = 1; yearday > days_in_month [ leap ] [ month_index ]; month_index++ )
		yearday -= days_in_month [ leap ] [ month_index ];

	printf("Month: %d, Day: %d\n", month_index, yearday);

}

int daysBetween2Dates ( int month, int day, int year )
{
	int month_index, leap;

	checkLeapYear ( &leap, year );

	days_till_date = day;
	
	for ( month_index = 1; month_index < month; month_index++ )
		days_till_date += days_in_month[ leap ] [ month_index ];
}

void getDateToConvert ( int *month, int *day, int *year )
{
	printf ( "Month: " );	scanf ( "%d", month );

	printf ( "Day: " );	scanf ( "%d", day );

	printf ( "Year: " );	scanf ( "%d", year );
}

int main ( void )
{
	int day, month, year;

	system( "clear" );

	getDateToConvert ( &month, &day, &year );

	daysBetween2Dates ( month, day, year );

	printf("%d\n",days_till_date);

	convertYearToMonthnDay ( days_till_date, year );

	return 0;
}
