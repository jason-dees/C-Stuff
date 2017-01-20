#include <stdio.h>

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