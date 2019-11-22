#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "../Shared/stack.h"
#include "../Shared/getch.h"

#define MAXOP 100
#define MAXVAR 123
#define NUMBER '0'

double variables[MAXVAR];
int main() {
    char c;
    int i = 0;
    char s[MAXOP];
    double d[MAXOP];

    while ((c = getch()) != EOF) {
        if(c !=  '\n'){
           s[i++] = c;
        }
        else{
            s[i++] = '\0';
            ungets(s);
        }
    }
    printf("thing \n%s\n", s);
}