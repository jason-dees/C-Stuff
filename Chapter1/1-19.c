#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverseString(char s[]);
int stringLength(char s[]);

void main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        reverseString(line);
        printf("%s\n", line);
    }
    if(max > 0){
        printf("%s", longest);
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

void copy(char to[], char from[]){
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0'){
        ++i;
    }
}

void reverseString(char s[]){
    int i, length;

    length = stringLength(s) - 1;

    char copied[length];
    copy(copied, s);

    for(i = length; i > -1; --i){
        s[length -i] = copied[i];
    }
    s[length + 1] = '\0';
}

int stringLength(char s[]){
    int c = 0;
    while(s[c] != '\0'){
        c ++;
    }
    return c;
}
