#include <stdio.h>
#define MAX 100
/*
page 48
Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string 
s2 occurs, or -1 if s1 contains no characters from s2 (the standard library function strpbrk does the same job but 
returns a pointer to the location.)
*/

void readLine(char s[]);
int any(char s1[], char s2[]);

int main(){

	int lim;
	lim = MAX;
	char s1[lim], s2[lim];

	readLine(s1);
	readLine(s2);

	int place = any(s1, s2);
    
	printf("%d\n", place);
}

void readLine(char s[]){
	int isValid = 1;
	int i = 0;
	char c;
	while(isValid){
		isValid = i < MAX - 1 && (c = getchar()) != '\n' && c != EOF;
		s[i++] = c;
	}
}

int any(char s1[], char s2[]){
	int i, k, c;
	for(k = 0; s1[k] != '\0'; k++){
		c = s1[k];
		for(i = 0; s2[i] != '\0'; i++){
			if(s2[i] == s1[k]){
				return k;	
			}
		}
	}
	return -1;
}
