#include <stdio.h>
/*
page 88
Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a
recursive routine.
*/

#define MAX 100

void readLine(char []);
void itoa(int, char []);

int main(){
    char s[MAX];

    itoa(1234, s);
    printf("%s\n", s);
    itoa(-1234, s);

    printf("%s\n", s);
}


int itoar(int n, char s[], int i);

void itoa(int n, char s[]){
    itoar(n, s, 0);
}
int itoar(int n, char s[], int i){
	if(n < 0){
		//n = -n; // 2^wordsize-1 is greater than the max positive number
        s[i++] = '-';
        n = -n;
	}

printf("%d %d\n", n / 10, i);
    if(n / 10){
        i = itoar(n / 10,s, i);
    }
    s[i] = n% 10 + '0';
    s[++i] = '\0';
    return i;
}