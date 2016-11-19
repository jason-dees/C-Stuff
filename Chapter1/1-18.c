#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int getLine(char line[], int maxline);
int characterIsBlank(char c);
void copy(char to[], char from[]);

void main(){
    int len;
    char line[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0){
        printf("%s\n", line);
    }
}

int getLine(char s[], int lim){
    int c, i, lastChar, stringLength;
    lastChar = stringLength = 0;
    for(i = 0; i< lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
        if(!characterIsBlank( (char)c)){
            lastChar = i;
        }
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[lastChar + 1] = '\0';
    return i;
}

int characterIsBlank(char c){
    return c =='\t' || c == ' ';
}

