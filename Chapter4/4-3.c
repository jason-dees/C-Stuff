#include <stdio.h>
#include <stdlib.h>
#include "../Shared/stack.h"
#include "../Shared/getop.h"
/*
page 79
Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions 
for negative numbers.
*/

#define MAXOP 100
#define NUMBER '0'

int main(){
    int type;
    double op2, op3;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0){
                push(pop() / op2);
            }
            break;
        case '%':
            op2 = pop();
            op3 = pop() / op2;
            push((op3 - (int)op3) * op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            break;
        }
    }
}
