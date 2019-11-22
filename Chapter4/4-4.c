#include <stdio.h>
#include <stdlib.h>
#include "../Shared/stack.h"
#include "../Shared/getop.h"
/*
page 79
Add commands to prin the top element of the stack wihout popping it, duplicate it, and to swap the top two elements.
Add a command to clear the stack.
*/

#define MAXOP 100
#define NUMBER '0'

int main(){
    int type;
    char s[MAXOP];
    double d[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
        case NUMBER:
            push(atof(s));
            break;
        case '\n':
            printtop();
            swap();
            printtop();
            duplicate(d);
            printf("duped: %.2g\n", d[2]);
            clear();
            printtop();
            printf("\t%.8g\n", pop());
            break;
        default:
            break;
        }
    }
}