#include <stdio.h>
#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char line[], int maxline);
void detab(int tablength, char in[], char out[], int maxline);

int main(){
    int len;
    char line[MAXLINE];
    char detabbed[MAXLINE];

    while((len = getLine(line, MAXLINE)) > 0){
        detab(TABLENGTH, line, detabbed, MAXLINE);
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


void detab(int tablength, char in[], char out[], int lim){
    int c, i, j, k, spaceChar;
    j = k = 0;
    spaceChar = ' ';
    for(i = 0; i< lim - 1 && (c = in[i]) != EOF; ++i){
        if(c == '\t'){
            k = 0;
            while(k++ < tablength){
               out[j++] = spaceChar; 
            }
        }
        else{
            out[j++] = c;
        }
    }
}
