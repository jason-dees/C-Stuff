#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main(){
	printf("%d\n", day_of_year(1978,5,20));

	int pmonth, pday;
	//submits pointers to pmonth and pday to function
	int day = 60;
	month_day(1997, day, &pmonth, &pday);
	printf("Day %d is %d/%d\n",day, pmonth, pday);
}

//Not a fan of this declaration
static char *days[] = {
	(char[]) {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	(char[]) {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day){
	if(month > 12 || month < 1 || day < 1){
		return -1;
	}
	int i, leap;

	leap = (year%4 == 0 && year%100) != 0 || year%400 == 0;
	char *months = *(days + leap);
	if(day > *(months + month)){
		return -1;
	}

	for(i = 1; i< month; i++){
		day += *(months + i);
	}

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	if((yearday > 365 && !leap) || (yearday > 366 && leap) || yearday < 1){
		*pmonth = -1;
		*pday = -1;
		return;
	}
	//NOT(*days+leap), this is the first array's 0 or 1 value, then setting i down below compounds this issue
	char *months = *(days+leap);

	for(i = 1; yearday > *(months+i); i++){
		yearday -= *(months+i);
	}
	//changes values of pmonth and pday variables submitted
	*pmonth = i;
	*pday = yearday;
}