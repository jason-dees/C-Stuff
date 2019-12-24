#include <stdio.h>
#include <string.h>
#define MAXLINES 1000
#define TABLENGTH 4
/*
page 118
Write the program tail, which prints the last n lines of its input. By default,  n is 10, let us say, but it can be 
changed by an optional argument, so that
    tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the input or value of n. Write 
the program so it makes the best use of available storage; lines should be stored as in the sorting pgoram of 
section 5.6, not in a two dimensional array of fixed size.
*/

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
        if(nlines > 0){
            tail(taillength, lineptr, nlines);
        }
        else{
            printf("No lines to print \n");
        }
        return 0;
    }

}

#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);
void strcopy(char *s, char *t);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0 && len > 1){
        if(nlines >= maxlines || (p = alloc(len)) == NULL ){
            //with alloc(len+1), it allocates space for the string termination at the end
            return -1;
        }
        else{
            //This terminates the string since alloc(len) only allocates room for up to the new line, thus not 
            //terminating the string
            line[len - 1] = '\0'; 
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void tail(int taillength, char *lineptr[], int len){
    int i = 0;
    while(taillength-- > 0 && i < len ){
        printf("tail: %s\n", lineptr[i++]);
    }
}

int getLine(char *s, int lim){
    int i;
    //I want to refactor this
    for(i = 0; i< lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++){
        s++;
    }
    if(*s == '\n'){
        i++;
    }
    *(++s) = '\0';
    return i;
}

void strcopy(char *s, char *t){
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    return 0;
}