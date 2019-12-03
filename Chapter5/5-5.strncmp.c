#include <stdio.h>
/*
page 107
Write versions of library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of
their argument strings. For example, strncopy(s,t,n) copies at most n characters of t to s.
*/
int strncmp(char *, char *, size_t);

int main(){
    char amessage[] = "fgdfd";
    char bmessage[] = "fgli";

    printf("%d\n", strncmp(amessage, bmessage, 2));


    printf("%d\n", strncmp(amessage, bmessage, 4));
}

int strncmp(char *s, char *t, size_t n){
    int count = 0;
    for( ; *s == *t && count < n; s++, t++, count++){
        if(*s == '\0'){
            return 0;
        }
    }
    if(count == n){
        return *--s - *--t;
    }
    return *s - *t;
}