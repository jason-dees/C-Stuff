#include <stdio.h>
#define MAX 100
/*
page 60
Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t 
as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape 
sequences into the real characters.
*/

void readLine(char s[]);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(){

	int lim;
	lim = MAX;
	char s[lim], t[lim];

	readLine(s);

	escape(s, t);
    
	printf("%s\n", t);
	unescape(t, s);
    
	printf("%s\n", s);
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

void unescape(char s[], char t[]){
	int lim = MAX;
	int c, i, j, inEscape;
	i = j = inEscape = 0;
	while(i < MAX - 1 && (c = s[i++]) != '\0'){
		switch (c){
			case '\\':
				inEscape = 1;
				break;
            case 'n':
				if(inEscape){
					c = '\n';
				}
            case 't':
				if(inEscape){
					c = '\t';
				}
            default:
				inEscape = 0;
				t[j++] = c;
				break;
		}
	}
	t[j] = '\0';
}

void escape(char s[], char t[]){
	int lim = MAX;
	int c, i, j;
	i = j = 0;
	while(i < MAX - 1 && (c = s[i++]) != '\0'){
		switch (c){
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
            default:
				t[j++] = c;
				break;
		}
	}
	t[j] = '\0';
}
