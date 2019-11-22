#include <stdio.h>
#include "../Shared/stack.h"
#include "../Shared/getch.h"
/*
page 79
Write a routing unget(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or
should it just use ungetch?
*/

#define MAXOP 100

int main() {
    char c;
    int i = 0;
    char s[MAXOP];

    while ((c = getch()) != EOF && i < MAXOP) {
        if(c !=  '\n'){
           s[i++] = c;
        }
        else{
            s[i] = '\0';
            ungets(s);
        }
    }

    printf("\n%s\n", s);
}