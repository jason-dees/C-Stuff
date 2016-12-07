#include <stdio.h>
#define MAXLINE 1000
#define FOLDAT 20

int getLine(char line[], int maxline);
int hasOpenClose(char in[], char open, char close);

void main(){
    int len;
    char line[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0){
        fold(line, FOLDAT, MAXLINE);
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


int hasOpenClose(char in[], char open, char close){
}
