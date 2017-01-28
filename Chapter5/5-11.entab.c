#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char line[], int maxline);
void entab(int *, char *, char *);

int main(int argc, char *argv[]){
    int len;
    char line[MAXLINE];
    char entabbed[MAXLINE];
    int tablengths[MAXLINE];
    int i = 0;
    while(*++argv != 0){
        tablengths[i++] = atof(*argv);
    }

    while((len = getLine(line, MAXLINE)) > 0){
        entab(tablengths, line, entabbed);
        printf("%s", entabbed);
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


void entab(int *tablengths, char *in, char *out){
    int c, i, spaceCount, tabChar, spaceChar, tabCount, tablength;
    spaceCount = 0;
    spaceChar = '_';
    tabChar = '-';
    while((c = *in++) != EOF && c != '\0'){
        tablength = *tablengths;
        if(c == ' '){
            spaceCount ++;
        }
        else if(c == '\t'){
            spaceCount += tablength;
        }
        else{
            tabCount = spaceCount / tablength;
            spaceCount = spaceCount % tablength;
            if(tabCount > 0){
                tablengths++;
            }
            while(tabCount-- > 0){
                *out++ = tabChar;
            }
            while(spaceCount-- > 0){
                *out++ = spaceChar;
            }
            *out++ = c;
            spaceCount = 0;
        }
    }
    *out = '\0';
}
