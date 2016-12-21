#include <stdio.h>
#define MAX 100

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
		s[i] = c;
		++i;
	}
}

int any(char s1[], char s2[]){
	int i, j, k, c;
	for(k = 0; s2[k] != '\0'; i++){
		c = s2[k];
		for(i = j = 0; s1[i] != '\0'; i++){
			if(s1[i] == c){
				return i;	
			}
		}
	}
	return -1;
}
