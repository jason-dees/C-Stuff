#include <stdio.h>

int getLine(char *);

int main(){
    int len;
    char line[] = "";

    while((len = getLine(line)) > 0){
        printf("%s\n", line);
    }
}

int getLine(char *s){
    int c, i;
    i = 0;
    while((*s = getchar()) != EOF && *s++ != '\n'){
        putchar(*s);
        i++;
    }
    *s = '\0';
    return i;
}
