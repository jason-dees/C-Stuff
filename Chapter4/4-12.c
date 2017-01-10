#include <stdio.h>

#define MAX 100

void readLine(char []);
int itoa(int, char [], int);

int main(){
    char s[MAX];

    itoa(1234, s, 0);
    printf("%s\n", s);
    itoa(-1234, s, 0);

    printf("%s\n", s);
}

 
int itoa(int n, char s[], int i){
	if(n < 0){
		//n = -n; // 2^wordsize-1 is greater than the max positive number
        s[i++] = '-';
        n = -n;
	}

    if(n / 10){
        i = itoa(n / 10,s, i);
    }
    s[i] = n% 10 + '0';
    s[++i] = '\0';
    return i;
}