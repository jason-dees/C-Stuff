#include <stdio.h>
#include <string.h>
#define MAX 100

void readLine(char s[]);
void itoa(int n, char s[]);
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim];
	itob(-1 * ((1 << 31) - 1) - 1, s, 2);
	printf("%s\n", s);

	itob(30, s, 16);
    
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

void itob(int n, char s[], int b){
	int i, sign, one, modded;
	one = 1;
	if((sign = n) < 0){
		//n = -n; // 2^wordsize-1 is greater than the max positive number
		one = -1;
	}
	i = 0;

	do{
		modded = n % b * one;
		if(modded < 10){
			s[i++] = modded + '0';
		}
		else{
			modded -= 10;
			s[i++] = modded + 'A';
		}
	}while((n /= b) != 0);

	if(sign < 0){
		s[i++] = '-';
	}

	s[i] = '\0';

	reverse(s);
}