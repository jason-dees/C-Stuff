#include <stdio.h>
int getint(int *);

int main(){
    int *i;
    *i = 2;
    while(getint(i) != EOF){
        printf("%d\n", *i);
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn){
    int c, sign;

    while(isspace(c = getch())){
        ;
    }

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-'){
        c = getch();
    }
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }    

    if(!isdigit(c)){
        ungetch(c);
    }

    *pn *= sign;

    if(c != EOF){
        ungetch(c);
    }

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(c == EOF){
        c = ' ';
    }
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters\n");
    }
    else{
        buf[bufp++] = c;
    }
}