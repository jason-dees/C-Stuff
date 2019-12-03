#include <stdio.h>
/*
page 107
Write versions of library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of
their argument strings. For example, strncopy(s,t,n) copies at most n characters of t to s.
*/
void strncpy(char *, char *, size_t);

int main(){
    char amessage[] = "";
    char bmessage[] = "fghi";

    strncpy(amessage, bmessage, 2);
    printf("%s\n", amessage);

    strncpy(amessage, bmessage, 4);
    printf("%s\n", amessage);
}

void strncpy(char *dest, char *src, size_t n){
    int count = 0;

    while((*dest++ = *src++) != '\0' && ++count < n){
    }
    *dest = '\0';
}