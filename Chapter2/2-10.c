#include <stdio.h>
#define MAX 100

void readLine(char s[]);
int lower(int c);

int main(){

	int lim;
	lim = MAX;
	char s1[lim];

	readLine(s1);
    
	printf("%s\n", s1);
}

void readLine(char s[]){
	int isValid = 1;
	int i = 0;
	char c;
	while(isValid){
		isValid = i < MAX - 1 && (c = getchar()) != '\n' && c != EOF;
		s[i] = lower(c);
		++i;
	}
	s[i] = '\0';
}

int lower(int c){
	int isUpper = c >= 'A' && c <= 'Z';
	return isUpper ? c + 'a' - 'A' : c;
}
