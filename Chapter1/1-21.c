#include <stdio.h>
#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char line[], int maxline);
void entab(int tablength, char in[], char out[], int maxline);

void main(){
    int len;
    char line[MAXLINE];
    char entabbed[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0){
        entab(TABLENGTH, line, entabbed, MAXLINE);
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


void entab(int tablength, char in[], char out[], int lim){
    int c, i, j, k, spaceChar, spaceCount, tabChar;
    j = k = spaceCount = 0;
    spaceChar = ' ';
    tabChar = 'x';
    for(i = 0; i< lim - 1 && (c = in[i]) != EOF; ++i){
        if(c == spaceChar){
            if(++spaceCount == tablength){
               out[j++] = tabChar; 
               spaceCount = 0;
            }
        }
        else{
            while(spaceCount-- > 0){
                out[j++] = spaceChar;
            }
            spaceCount = 0;
            out[j++] = c;
        }
    }
    out[j] = '\0';
}
