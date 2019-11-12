#include <stdio.h>
#define MAXLINE 1000
#define FOLDAT 20
/*
Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that 
occurs before the n-th column of input. Make sure your pgoram does something intelligent with very long lines, and if 
there are no blanks or tabs before the specified column.
*/

int getLine(char line[], int maxline);
void fold(char in[], int foldAt, int maxline);
int isSpace(char c);
int isEndLine(char c);

int main(){
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


void fold(char in[], int foldAt, int lim){
    int c, i,  spaceChar, noFoldCount;
    noFoldCount = 0;
    spaceChar = ' ';
    for(i = 0; i< lim - 1 && !isEndLine(c = in[i]); ++i){
        if(noFoldCount >= foldAt && isSpace(c)){
            noFoldCount = 0;
            printf("\n");
        }
        else if(isSpace(c) && noFoldCount == 0){
        }
        else{
            putchar(c);
            noFoldCount++;
        }
    }
    putchar('\n');
}

int isSpace(char c){
    return c == ' ' || c == '\t';
}
int isEndLine(char c){
    return c == EOF || c == '\n';
}
