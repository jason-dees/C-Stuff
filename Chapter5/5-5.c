#include <stdio.h>
/*
page 107
Write versions of library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of
their argument strings. For example, strncopy(s,t,n) copies at most n characters of t to s.
*/

void strcat(char *s, char *tm_mon);

int main(){
    char amessage[] = "abcde";
    char bmessage[] = "fghi";

    strcat(amessage, bmessage);
    printf("%s\n", amessage);
}

void strcat(char *s, char *t){

    while(*++s !=  '\0'){ }
    while((*s++ = *t++) != '\0'){ }
}