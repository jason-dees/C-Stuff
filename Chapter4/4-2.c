#include <stdio.h>
#include <math.h>
#define MAX 100
/*
page 73
Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E 
and an optionally signed component.
*/

int getLine(char s[], int lim);
double atof(char s[]);
double subatof(char s[], int *i);

int main(){

	int lim;
	lim = MAX;
	char s[lim], t[lim];

	getLine(s, lim);

	printf("%f\n", atof(s));
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

double atof(char s[]){
	double val, power, eval;
	int i, sign, esign;

	for(i = 0; isspace(s[i]); i++){}
	val = subatof(s, &i);

	if(s[i] == 'e'){
		i++;
		eval = subatof(s, &i); 
		val = val * pow(10,eval);
	}

	return val;
}

double subatof(char s[], int *i){
	//not quite what they had in mind for this but oh well;
	double val, power;
	int sign, k;
	k = (*i);
	sign = (s[k] == '-') ? -1 : 1;
	if(s[k] == '+' || s[k] == '-'){
		k++;
	}

	for(val = 0.0; isdigit(s[k]); k++){
		val = 10.0 * val + (s[k] - '0');
	}
	if(s[k] == '.'){
		k++;
	}

	for(power = 1.0; isdigit(s[k]); k++){
		val = 10.0 * val + (s[k] - '0');
		power *= 10.0;
	}
	(*i) = k;
	return sign * val/power;
}