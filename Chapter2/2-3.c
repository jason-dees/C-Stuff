#include <stdio.h>
#include <math.h>
/*
page 46
Write a function htoi(s), which converts a string of hexadecimal digits (including an option 0x, or 0X) into its 
equivalent integer value. The allowable digits are 0 through 9, a through f and A through F.
*/

int htoi(char s[]);

int main(){

	int i, lim, c, isValid;
	lim = 100;
	i = 0;
	isValid = 1;
	char s[lim], out[lim];

	while(isValid){
		isValid = i < lim - 1 && (c = getchar()) != '\n' && c != EOF;
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	i = htoi(s);
    
	printf("\n%d\n", i);
}


int htoi(char s[]){
	int i, o, isHex, currentNumber, sumNumber, numbersCount = 0;
	int numbers[100];
	isHex = 1;
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		i += 2;
	}
	
	for(; isHex; ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			currentNumber = s[i] - '0';
		}
		else if(s[i] >= 'a' && s[i] <= 'f'){
			currentNumber = s[i] - 'a' + 10;
		}
		else if(s[i] >= 'A' && s[i] <= 'F'){
			currentNumber = s[i] - 'A' + 10;
		}
		else{
			isHex = 0;
		}
		if(isHex){
			numbers[numbersCount++] = currentNumber;
		}
	}
	i = numbersCount;

	for(o = 0; o < i; ++o){
		if(numbers[o] > 0){
			sumNumber += pow(16, (--numbersCount)) -1 + numbers[o];
		}
	}

	return sumNumber;
}
