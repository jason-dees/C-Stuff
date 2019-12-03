#include <stdio.h>
#include <math.h>
/*
page 107
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.
*/
int htoi(char *);
int getLine(char *);

int main(){

	int i, lim, c, isValid;
	lim = 100;
	i = 0;
	isValid = 1;
	char s[100] = " ";

	getLine(s);

	i = htoi(s);

	printf("\n%d\n", i);
}

int getLine(char *s){
    int c, i;
    i = 0;

    while((*s = getchar()) != EOF && *s != '\n' && *s != '\0'){
        s++;
        i++;
    }
    *s = '\0';
    return i;
}

int getNumber(char);

int htoi(char *s){
	int sumNumber;
	int numbersCount = -1;
	int numbers[100];
	int *nums = &numbers[0];
	if(*s == '0' && (*(s+1) == 'x' || *(s+1) == 'X')){
		s += 2;
	}

	while((numbers[++numbersCount]  = getNumber(*s++)) >-1){
		;
    }

	sumNumber = 0;
	while(--numbersCount > -1){
		if(*nums> 0){
			sumNumber += pow(16, (numbersCount)) * *nums++;
		}
	}

	return sumNumber;
}

int getNumber(char n){
	if(n >= '0' && n <= '9'){
		return n - '0';
	}
	else if(n >= 'a' && n <= 'f'){
		return n - 'a' + 10;
	}
	else if(n >= 'A' && n <= 'F'){
		return n - 'A' + 10;
	}
	return -1;
}
