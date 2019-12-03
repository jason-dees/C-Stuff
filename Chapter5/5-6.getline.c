#include <stdio.h>
/*
page 107
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.
*/

int getLine(char *);

int main(){
    int len;
    char line[100] = " ";

    while((len = getLine(line)) > 0){
        printf("%s\n", line);
    }
}

int getLine(char *s){
    int c, i;
    i = 0;

    while((*s = getchar()) != EOF && *s != '\n' && *s != '\0'){
        s++;
        i++;
    }
    *s = '\0';
    return i;
}
