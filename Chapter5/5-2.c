#include <stdio.h>
int getfloat(float *);

int main(){
    float *i;
    *i = 1.0;
    int gotten; 
    while((gotten = getfloat(i)) || 1){
        if(gotten == EOF){
            return -1;
        }
        if(gotten > 0){
            printf("%f\n", *i);
        }
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn){
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
    if(c != '.' && !isdigit(c)){
        printf("%c\n", c);
        ungetch(c);
        return 0;
    }
    float afterDecimal = 1.0;
    for(*pn = 0; isdigit(c) || c == '.'; c = getch()){
        if(afterDecimal < 1){
            *pn = *pn + (c - '0') * afterDecimal;
        }
        if(c == '.' || afterDecimal < 1){
            afterDecimal /= 10;
        }
        else if(afterDecimal == 1){
            *pn = 10 * *pn + (c - '0');
        }
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