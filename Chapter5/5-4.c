#include <stdio.h>

int strend(char *, char);

int main(){
    char amessage[] = "abcde";
    char bmessage[] = "fghi";

    printf("%d\n", strend(amessage, 'e'));
    printf("%d\n", strend(amessage, 'a'));
}

int strend(char *s, char t){
    while(*++s != '\0'){
    }
    return *--s == t;
}