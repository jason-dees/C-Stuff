#include <stdio.h>

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