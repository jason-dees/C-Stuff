#include <stdio.h>
#include <string.h>
#define MAXLINES 1000
#define TABLENGTH 4

int readlines(char *lineptr[], int maxlines);
void tail(int taillength, char *lineptr[], int len);

char *lineptr[MAXLINES];
int main(int argc, char *argv[]){
    int taillength = 10;
    int nlines;

    while(--argc > 0 && (*++argv)[0] == '-'){
        taillength = atoi(*argv) * -1;
    }
    if(taillength == 0){
        taillength = 0;
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        tail(taillength, lineptr, nlines);
        return 0;
    }

}

#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;
        }
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void tail(int taillength, char *lineptr[], int len){
    while(taillength-- > 0){
        printf("%s\n", lineptr[--len]);
    }
}

int getLine(char *s, int lim){
    int c, i;
    while(i++ < lim && (c = getchar()) != EOF && c != '\n'){
        *s++ = c;
    }
    if(i == 1 && c == '\n'){
        --i;
    }
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