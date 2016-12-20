#include <stdio.h>

int main(){

	int i, lim, c, isValid;
	lim = 100;
	i = 0;
	isValid = 1;
	char s[lim];

	while(isValid){
		isValid = i < lim - 1 && (c = getchar()) != '\n' && c != EOF;
		s[i] = c;
		++i;
	}
    
	s[i] = '\0';
	printf("\n%s", s);
}

