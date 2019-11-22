#include <stdio.h>
#define MAX 100
/*
page 71
WRite the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or -1 if there is 
none.
*/

int getLine(char s[], int lim);
int strrindex(char s[], char t);

int main(){

	int lim;
	lim = MAX;
	char s[lim], t[lim];

	getLine(s, lim);

	printf("%d\n", strrindex(s, 'a'));
}

int getLine(char s[], int lim){
	int isValid = 1;
	int i = 0;
	char c;
	while(isValid){
		isValid = i < MAX - 1 && (c = getchar()) != '\n' && c != EOF;
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int strrindex(char s[], char t){
	int i, rightmost;
	rightmost = -1;
	for(i = 0; s[i] != '\0'; i++){
		if(s[i] == t){
			rightmost = i;
		}
	}
	return rightmost;
}