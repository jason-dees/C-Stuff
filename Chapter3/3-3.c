#include <stdio.h>
#define MAX 100

void readLine(char s[]);
void expand(char s[], char t[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim], t[lim];

	readLine(s);

	expand(s, t);
    
	printf("%s\n", t);
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
	s[i] = '\0';
}

void expand(char s[], char t[]){
	int lim = MAX;
	int b, c, d, i, j;
	i = j = 0;

	while(i < lim - 1 && (c = s[i++]) != '\0'){
		if(c == '-'){
			d = s[i++];
			while(b++ < d){
				t[j++] = b;
			}
			b = d;
		}
		else{
			t[j++] = c;
			b = c;
		}
	}

}