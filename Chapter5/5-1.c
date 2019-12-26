#include <stdio.h>
#include <ctype.h>
#include "../Shared/getch.h"

#define isvalidcharacter(c) isdigit(c) || c == EOF || c == '+' || c == '-'
/*
page 97
As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a
character back on the input
*/

int getint(int *);

int main(){
    int *i;
    *i = 2;
    int gotten;
    while((gotten = getint(i)) || 1){
        if(gotten == EOF){
            return -1;
        }
        if(gotten > 0){
            printf("out %d\n", *i);
        }
    }
}
int getint(int *pn){
    int c, sign;

    while (isspace(c = getch()) || !(isvalidcharacter(c))){
            ;
    }

    sign = (c == '-') ? -1 : 1;

    if(c == '+' || c == '-'){
        int d = getch();
        if(!isdigit(d)){
            ungetch(c);
            return 0;
        }
        c = d;
    }
    for(*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if(c != EOF){
        ungetch(c);
    }

    return c;
}