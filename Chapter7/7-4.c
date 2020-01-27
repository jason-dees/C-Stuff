#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
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
    while(getLine(line, MAXWORD) == 0 || isspace(*line)){
        //i want to spin here
    }
    char words[MAXWORD][MAXWORD];
    char word[MAXWORD];
    char *wordptr = word;
    char **wordsptr = words;
    for(char *lineiter = line; *lineiter > 0; lineiter++){
        if(isspace(*lineiter)){
            *wordptr = '\0';
            if(strlen(word) > 0){
                *wordsptr++ = word;
            }
            wordptr = word;
            continue;
        }
        *wordptr++ = *lineiter;
    }
    wordsptr = words;
    //I can cycle through 1 then the other, ignoring spaces
    for(char *lineiter = fmt; *lineiter > 0; lineiter++) {
        if(*lineiter != '%'){
            continue;
        }
        switch(*++lineiter){
            case 'd':
                ival = va_arg(ap, int *);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf("%s", *(wordsptr));
                sval = *wordsptr++;
                break;
            default:
                printf("%c ", *lineiter);
                break;
        }
    }

    va_end(ap);/* clean up when done */
}
int main(int argc, char *argv[]){
    char *a, *b, *c;
    // scanf("%d %d %d", &a, &b, &c);
    // printf("printing: %d %d %d\n", a, b, c);
    minscanf("%s %s %s", a, b, c);
    printf("printing: %s %s %s\n", a, b, c);
    return 0;
}