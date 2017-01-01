#include <stdio.h>
#include <string.h>
#define MAX 100

void readLine(char s[]);
void itoa(int n, char s[], int p);
void reverse(char s[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim];
	itoa(23, s, 5);
	printf("%s\n", s);
	itoa(-23, s, 5);
	printf("%s\n", s);
}

void reverse(char s[]){
	int c, i, j;
	for(i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[], int p){
	int i, sign, one;
	one = 1;
	if((sign = n) < 0){
		//n = -n; // 2^wordsize-1 is greater than the max positive number
		one = -1;
	}
	i = 0;

	do{
		s[i++] =  n % 10 * one + '0';
	}while((n /= 10) != 0);
	while(i < p){
		s[i++] = '0';
	}

	if(sign < 0){
		s[i++] = '-';
	}

	s[i] = '\0';

	reverse(s);
}