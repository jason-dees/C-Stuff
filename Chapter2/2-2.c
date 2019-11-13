#include <stdio.h>
/*
page 42
isValid = i < lim - 1 && (c = getchar()) != '\n' && c != EOF;

Write a loop equivalent to the for loop above without using && or ||.
*/

int main(){

	int i, lim, c, isValid;
	lim = 100;
	i = 0;
	isValid = 1;
	char s[lim];

	while(isValid){
		c = getchar();
		isValid = (i < lim - 1) * (c != '\n') * (c != EOF);
		s[i++] = c;
	}
    
	s[i] = '\0';
	printf("\n%s", s);
}

