#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 100
#define MAXVAR 123
#define NUMBER '0'
#define SIN 1
#define EXP 2 
#define TAN 3 
#define COS 4 
#define POW 5 

int getop(char []);
void push(double);
double pop(void);
double popvar(void);
int opis(char []);
void domathop(char []);
double getvariablevalue(double);

double variables[MAXVAR];
int main(int argc, char *argv[]){
    int type, mathOpIndex, variable;
    double op1, op2, op3, lastPrint;
    char s[MAXOP];
    char mathOp[4];
    mathOpIndex = 0;

    while(--argc > 0){
        type = getop(*++argv);
        switch(type){
        case NUMBER:
            push(atof(*argv));
            break;
        case '+':
            op1 = popvar();
            op2 = popvar();
            push(op1 + op2);
            break;
        case '*':
            op1 = popvar();
            op2 = popvar();
            push(op1 * op2);
            break;
        case '-':
            op2 = popvar();
            op1 = popvar();
            push(op1 - op2);
            break;
        case '/':
            op2 = popvar();
            op1 = popvar();
            if(op2 != 0.0){
                push(op1 / op2);
            }
            break;
        case '%':
            op2 = popvar();
            op3 = popvar() / op2;
            push((op3 - (int)op3) * op2);
            break;
        case '=':
            op1 = pop();
            variable = (int)op1;
            if(islower(variable) || isupper(variable)){
                variables[variable] = popvar();
                push(variable);
            }
            else{
                printf("The popped value %f is not a valid variable \n", op1);
            }
            break;
        case '\n':
            lastPrint = popvar();
            printf("\t%.8g\n", lastPrint);
            mathOpIndex = 0;
            break;
        case ' ':
            while(mathOpIndex-- > 0){// I don't like this but i need to pop extra variables from stuff like tan
            //how can i do that without this?
                pop();
            }
            mathOpIndex = 0;
            break;
        default:
            mathOp[mathOpIndex++] = type;
            if(mathOpIndex == 3){
                mathOp[mathOpIndex] = '\0';
                domathop(mathOp);
                mathOpIndex = 0;
            }
            else if(mathOpIndex == 1 && (islower(type) || isupper(type))){
                push(type);
                if(variables[type] != 0){
                    mathOpIndex = 0; 
                }
            }
            break;
        }
    }
    lastPrint = popvar();
    printf("\t%.8g\n", lastPrint);
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
    switch(opis(op)){
        case SIN:
            push(sin(popvar()));
            break;
        case COS:
            push(cos(popvar()));
            break;
        case TAN:
            op2 = popvar();
            push(tan(op2));
            break;
        case EXP:
            push(exp(popvar()));
            break;
        case POW:
            op2 = popvar();
            push(pow(popvar(), op2));
            break;
    }
}

double getvariablevalue(double val){
    int intval = (int)val;
    if(intval == val && (islower(intval) || isupper(intval)) && variables[intval] != 0){
        return variables[intval];
    }
    return val;
}

double popvar(void){
    return getvariablevalue(pop());
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

int getch(void);
void ungetch(int);

int getop(char *s){
    int hasMinus, hasdig;
    hasdig = hasMinus = 0;
    
    if(*s == ' ' || *s == '\t'){ 
        return *s;
    }

    //it is a negative number when it's a - and the next character is a digit
    if(!isdigit(*s) && *s != '.' && *s != '-'){
        return *s;
    }

    if(*s == '-'){
        s++;
        hasMinus = 1;
    }

    if(isdigit(*s) || *s == '-'){
        while(isdigit(*++s)){}
    }

    if(*s == '.'){
        while(isdigit(*++s)){}
    }

    *s = '\0';
    if(hasMinus && !hasdig){
        return '-';
    }

    return NUMBER;
}

#define BUFSIZE 1 

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