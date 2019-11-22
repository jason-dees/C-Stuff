#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* 
page 79
Add access to library functions like sin, exp, and pow. See <math.h> in appendix B, section 4.
*/

#define MAXOP 100
#define NUMBER '0'
#define SIN 1
#define EXP 2 
#define TAN 3 
#define COS 4 
#define POW 5 

int getop(char []);
void push(double);
double pop(void);
int opis(char []);
void domathop(char []);

int main(){
    int type, mathOpIndex;
    double op2, op3;
    char s[MAXOP];
    char mathOp[4];
    mathOpIndex = 0;

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
            mathOp[mathOpIndex++] = type;
            if(mathOpIndex == 3){
                mathOp[mathOpIndex] = '\0';
                domathop(mathOp);
                mathOpIndex = 0;
            }
            break;
        }
    }
}
int opis(char op[]){
    if(strcmp(op, "sin") == 0){
        return SIN;
    }
    if(strcmp(op, "cos") == 0){
        return COS;
    }
    if(strcmp(op, "tan") == 0){
        return TAN;
    }
    if(strcmp(op, "exp") == 0){
        return EXP;
    }
    if(strcmp(op, "pow") == 0){
        return POW;
    }
    return -1;
}

void domathop(char op[]){
    double op2;
    //This stuff is in radians, not degrees
    switch(opis(op)){
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;
    }
}
