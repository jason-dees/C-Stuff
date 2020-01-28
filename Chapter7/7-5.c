#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../Shared/stack.h"
#include "../Shared/getop.h"
#define MAXWORD 5
/*
page 159
Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversions.
*/
#define NUMBER '0'
int whatop(char *s){
    int i = 0, hasMinus = 0, hasDig = 0;
    if(!isdigit(*s) && *s != '.' && *s != '-'){
        return *s;
    }
    if(*s == '-'){
        i = 1;
        hasMinus = 1;
    }
    if (isdigit(*s) || *s == '-'){
        while (isdigit(*s++) || *s == '.'){ }
    }
    if(hasMinus){
        return '-';
    }

    return NUMBER;

}
int main(int argc, char *argv[]) {
    printf("Must use ctrl + d to break and computer \n");
    //1 2 - 4 5 + * = (1-2) * (4-5)
    char operations[MAXWORD][MAXWORD];
    char buffer[MAXWORD];

    int i = 0, totalOps = 0;
    double op2, op3;
    while(scanf("%s", operations[i]) > 0 && i < MAXWORD){
        i++;
        totalOps++;
    }

    for (int i=0; i<totalOps; i++){
        int type;
        type = whatop(operations[i]);
        switch(type){
        case NUMBER:
            push(atof(operations[i]));
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
        default:
            break;
        }
    }
    printf("\t%.8g\n", pop());

    return 0;
}