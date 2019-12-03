#include <stdio.h>
/*
page 107
Write a pointer version of the function strcat that we showed in chapter 2: strcat(s,t) copies the string t to end of s.
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