#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(){
	printf("%d\n", day_of_year(1978,5,20));
	
	int pmonth, pday;
	month_day(1, 1, &pmonth, &pday);
	printf("%d/%d\n", pmonth, pday);
}

static char (*days)[13] = (char [][13]){
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
	if(month > 12 || month < 1 || day < 1){
		return -1;
	}
	int i, leap;

	leap = (year%4 == 0 && year%100) != 0 || year%400 == 0;

	if(day > days[leap][month]){
		return -1;
	}

	for(i = 1; i< month; i++){
		day += days[leap][i];
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;

	leap = (year%4 == 0 && year%100) != 0 || year%400 == 0;

	if((yearday > 365 && !leap) || (yearday > 366 && leap) || yearday < 1){
		*pmonth = -1;
		*pday = -1;
		return;
	}

	for(i = 1; yearday > days[leap][i]; i++){
		yearday -= days[leap][i];
	}

	*pmonth = i;
	*pday = yearday;
}