#include <stdio.h>
#define MAX 100

void readLine(char s[]);
void squeezeChar(char s[], int c);
void squeeze(char s1[], char s2[]);

int main(){

	int lim;
	lim = MAX;
	char s1[lim], s2[lim];

	readLine(s1);
	readLine(s2);

	squeeze(s1, s2);
    
	printf("%s\n", s1);
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

void squeezeChar(char s[], int c){
	int i, j;

	for(i = j = 0; s[i] != '\0'; i++){
		if(s[i] != c){
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

void squeeze(char s1[], char s2[]){
	int i;
	for(i = 0; s2[i] != '\0'; i++){
		squeezeChar(s1, s2[i]);
	}
}
