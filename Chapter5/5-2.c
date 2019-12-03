#include <stdio.h>
#include "../Shared/getch.h"

#define isvalidcharacter(c) isdigit(c) || c == EOF || c == '+' || c == '-' || c == '.'
#define isnumeric(c) isdigit(c) || c == '.'

int getfloat(float *);
/*
page 97
Write getfloat, the floating-point analog of geting. What type does getfloat return as its function value?
*/

int main(){
    float *i;
    *i = 1.0;
    int gotten;
    while((gotten = getfloat(i)) || 1){
        if(gotten == EOF){
            return -1;
        }
        if(gotten > 0){
            printf("out %f\n", *i);
        }
    }
}

int getfloat(float *pn){
    int c, sign;

    while (isspace(c = getch()) || !(isvalidcharacter(c))) {
        ;
    }
    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-'){
        int d = getch();
        if (!(isnumeric(d))) {
            ungetch(c);
            return 0;
        }
        c = d;
    }
    float afterDecimal = 1.0;
    for(*pn = 0; isnumeric(c); c = getch()){
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