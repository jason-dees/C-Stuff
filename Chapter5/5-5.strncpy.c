#include <stdio.h>

void strncopy(char *, char *, size_t);

int main(){
    char amessage[] = "";
    char bmessage[] = "fghi";

    strncopy(amessage, bmessage, 2);
    printf("%s\n", amessage);

    strncopy(amessage, bmessage, 4);
    printf("%s\n", amessage);
}

void strncopy(char *dest, char *src, size_t n){
    int count = 0;

    while((*dest++ = *src++) != '\0' && ++count < n){
    }
    *dest = '\0';
}