#include <stdio.h>
#include <string.h>
#include "readlines.h"

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0 && len > 1){
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            //with alloc(len+1), it allocates space for the string termination at the end
            return -1;
        }
        else {
            //This terminates the string since alloc(len) only allocates room for up to the new line, thus not
            //terminating the string
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int getLine(char *s, int lim){
    int i;
    for(i = 0; i< lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++){
        s++;
    }
    if(*s == '\n'){
        i++;
    }
    *(++s) = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp +=n;
        return allocp -n;
    }
    return 0;
}