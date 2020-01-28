#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#define MAXWORD 1000
/*
page 159
Write a private version of scanf analogous to minprintf from the previous section.
*/
int getLine(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        *s++ = c;
    }
    // if (c == '\n')
    // {
    //     *s++ = c;
    //     ++i;
    // }
    *s = '\0';
    return i;
}

void minscanf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int *ival;
    double *dval;
    va_start(ap, fmt);

    char line[MAXWORD];
    while(getLine(line, MAXWORD) == 0){
        //i want to spin here
    }
    char word[MAXWORD];
    char *wordptr = word;
    char *lineiter = line;

    for(;isspace(*lineiter); lineiter++){
    }
    for(char *fmtiter = fmt; *fmtiter > 0; fmtiter++) {
        if(*fmtiter != '%'){
            continue;
        }
        for(; *lineiter; lineiter++){
            if(isspace(*lineiter)){
                *wordptr = '\0';
                wordptr = word;
                break;
            }
            *wordptr++ = *lineiter;
        }
        switch(*++fmtiter){
            case 'd':
                ival = va_arg(ap, int *);
                *ival = atoi(word);
                break;
            case 's':
                sval = va_arg(ap, char *);
                strcpy(sval, word);
                break;
            default:
                printf("%c ", *fmtiter);
                break;
        }
        *wordptr = '\0';
        for(;isspace(*lineiter); lineiter++){
        }
    }

    va_end(ap);/* clean up when done */
}

int main(int argc, char *argv[]){
    int a = 17;
    char b[5], c[5];
    // scanf("%d %d %d", &a, &b, &c);
    // printf("printing: %d %d %d\n", a, b, c);
    minscanf("%d %s %s", &a, b, c);
    printf("printing: %d %s %s\n", a, b, c);
    return 0;
}