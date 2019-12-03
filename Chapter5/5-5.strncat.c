#include <stdio.h>
/*
page 107
Write versions of library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of
their argument strings. For example, strncopy(s,t,n) copies at most n characters of t to s.
*/
void strncat(char *, char *, size_t);

int main(){
    char amessage[] = "";
    char bmessage[] = "fghi";

    strncat(amessage, bmessage, 2);
    printf("%s\n", amessage);

    strncat(amessage, bmessage, 4);
    printf("%s\n", amessage);
}

void strncat(char *dest, char *src, size_t n){
    int count = 0;
    if(*dest != '\0'){
        while(*++dest != '\0'){
            ;
        }
    }
    while((*dest++ = *src++) != '\0' && ++count < n){
    }
    *dest = '\0';
}