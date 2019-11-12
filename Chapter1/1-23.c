#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#define SLASH_STAR 1
#define STAR_SLASH 2 
/*
Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constancts 
properly. C comments do not nest.
*/

int getLine(char line[], int maxline);
void removeComment(char in[]);
int searchComment(char in[]);
int stripComment(char in[], int start, int end);

int main(){
    int len, inComment, hasComment;
    char line[MAXLINE];
    inComment = hasComment = 0;

    while((len = getLine(line, MAXLINE)) > 0){
        hasComment = searchComment(line);
        if(hasComment == SLASH_STAR){
            inComment = SLASH_STAR;
            printf("%s\n", line);
        }
        else if(hasComment == STAR_SLASH){
            inComment = 0;
            printf("%s\n", line);
        }
        else if(!inComment){
            printf("%s\n", line);
        }
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

int searchComment(char in[]){
    char* slashStar = strstr(in, "/*");
    int slashStarPosition = -1; 

    char* slashSlash = strstr(in, "//");
    int slashSlashPosition = -1; 

    char* starSlash = strstr(in, "*/");
    int starSlashPosition = -1; 

    if(slashStar != NULL){
        slashStarPosition = slashStar - in;
    }
    if(slashSlash != NULL){
        slashSlashPosition = slashSlash - in;
    }
    if(starSlash != NULL){
        starSlashPosition = starSlash - in;
    }
    if(slashStarPosition > -1 && starSlashPosition > -1){
        stripComment(in, slashStarPosition, starSlashPosition + 2);
        return 0;
    }
    if(slashStarPosition > -1){
        stripComment(in, slashStarPosition, strlen(in));
        return SLASH_STAR;
    }
    if(slashSlashPosition > -1){
        stripComment(in, slashSlashPosition, strlen(in));
        return 0;
    }
    if(starSlashPosition > -1){
        stripComment(in, 0, starSlashPosition + 2);
        return STAR_SLASH;
    }
}

int stripComment(char in[], int start, int end){
    int i = 0;
    for(i = start; i< end; i++){
        in[i] = ' ';
    }
}

