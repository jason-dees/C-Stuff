#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int main(){
    int type, tripleIndex;
    double op2, op3;
    char s[MAXOP];
    char triple[4];
    tripleIndex = 0;

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
            triple[tripleIndex++] = type;
            if(tripleIndex == 3){
                triple[tripleIndex] = '\0';
                //do the op~
                switch(opis(triple)){
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
                tripleIndex = 0;
            }
            break;
        }
    }
}
int opis(char op[]){
    if(strcmp(op,"sin") == 0){
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
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("Error: stack is full!! %g\n", f);
    }
}

double pop(void){
    if(sp > 0){
        return val[--sp];
    }
    return 0.0;
}

#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t'){}
    //it is a negative number when it's a - and the next character is a digit
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-'){
        return c;
    }

    i = 0;
    if(isdigit(c) || c == '-'){
        while(isdigit(s[++i] = c = getch())){}
    }
    else if(c != '.'){
        return '-';
    }

    if(c == '.'){
        while(isdigit(s[++i] = c = getch())){}
    }

    s[i] = '\0';
    if(c != EOF){
        ungetch(c);
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else{
        buf[bufp++] = c;
    }
}