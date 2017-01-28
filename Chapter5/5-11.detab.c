#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char line[], int maxline);
void detab(int *, char *, char *);

int main(int argc, char *argv[]){
    int len;
    char line[MAXLINE];
    char detabbed[MAXLINE];
    int tablengths[MAXLINE];
    int i = 0;
    while(*++argv != 0){
        tablengths[i++] = atof(*argv);
    }
    tablengths[i] = 0;

    while((len = getLine(line, MAXLINE)) > 0){
        detab(tablengths, line, detabbed);
        printf("%s", detabbed);
    }
}

int getLine(char s[], int lim){
    int c, i;
    for(i = 0; i< lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


void detab(int *tablengths, char *in, char *out){
    int c, i, j, k, spaceChar, tablength;
    j = k = 0;
    spaceChar = '_';
    while((c = *in++) != EOF && c != '\0'){
        if(c == '\t'){
            k = 0;
            while(k++ < *tablengths){
               *out++ = spaceChar; 
            }
            if(*++tablengths < 0){
                tablengths--;
            }
        }
        else{
            *out++ = c;
        }
    }
    *out = '\0';
}
