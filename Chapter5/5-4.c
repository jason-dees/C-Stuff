#include <stdio.h>
#include <string.h>
/*
page 107
Write the function strend(s,t), which returns 1 if the string occurs at the end of string s, and zero otherwise.
*/
int strend(char *, char *);

int main(){
    char amessage[] = "abcde";
    char bmessage[] = "defde";

    printf("%d\n", strend(amessage, "de"));
    printf("%d\n", strend(amessage, "d"));
    printf("%d\n", strend(bmessage, "de"));
    printf("%d\n", strend(bmessage, amessage));
}

int strend(char *s, char *t){
    if(*s == '\0'){ return 0; }
    while(*s++ != *t && *s != '\0'){
    }
    return strcmp(s-1, t) == 0 ? 1 : strend(s, t);
}