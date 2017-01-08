#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void printtop(void);
void swap(void);

int main(){
    int type;
    double op2, op3;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
        case NUMBER:
            push(atof(s));
            break;
        case '\n':
            printtop();
            swap();
            printtop();
            clear();
            printtop();
            printf("\t%.8g\n", pop());
            break;
        default:
            break;
        }
    }
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

void printtop(){
    printf("%f\n", val[sp - 1]);
}

void duplicate(double copy[]){
    int i = 0;
    while(i < sp){
        copy[i++] = val[i];
    }
}

void swap(){
    double first = pop();
    double second = pop();

    push(first);
    push(second);
}

void clear(){
    while(sp > 0){
        pop();
    }
}

#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[]){
    int i, c, hasMinus, hasdig;
    hasdig = hasMinus = 0;
    while((s[0] = c = getch()) == ' ' || c == '\t'){}
    //it is a negative number when it's a - and the next character is a digit
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-'){
        return c;
    }

    i = 0;
    if(c == '-'){
        i = 1;
        c = getch();
        hasMinus = 1;
    }

    if(isdigit(c) || c == '-'){
        while(isdigit(s[++i] = c = getch())){}
    }

    if(c == '.'){
        while(isdigit(s[++i] = c = getch())){}
    }

    s[i] = '\0';
    if(c != EOF){
        ungetch(c);
    }
    if(hasMinus && !hasdig){
        return '-';
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