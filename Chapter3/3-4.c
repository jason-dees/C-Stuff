#include <stdio.h>
#include <string.h>
#define MAX 100
/*
page 64
In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, 
the value of n equal to -2(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of the 
machine on which it runs.
*/

void readLine(char s[]);
void itoa(int n, char s[]);
void reverse(char s[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim];
	itoa(-1 * ((1 << 31) - 1) - 1, s);
    
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

void itoa(int n, char s[]){
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

	if(sign < 0){
		s[i++] = '-';
	}

	s[i] = '\0';

	reverse(s);
}