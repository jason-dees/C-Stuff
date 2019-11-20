#include <stdio.h>
#define MAX 100
/*
page 63
Write a function expand(s1,s2) that expands shorthand notation like a-z in the string s1 into the equivalent complete 
list abc...xyz in s2. Alllow for letters of either case and digits, and be prepared to handle cases like a-b-c and 
a-z0-9 and -a-z. Arrange that leading or tailing - is taken literally.
*/

void readLine(char s[]);
void expand(char s[], char t[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim], t[lim];
	//readLine(s);
	//expand(s, t);
	//printf("%s\n", t);

	expand("a-Z", t);
	printf("%s\n", t);
	expand("Z-a", t);
	printf("%s\n", t);
	expand("a-z", t);
	printf("%s\n", t);
	expand("a-zA-Z", t);
	printf("%s\n", t);
	expand("a-zA-Z0-9", t);
	printf("%s\n", t);
	expand("0-9a-zA-Z0-9", t);
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