#include <stdio.h>

int main(){
    int c, wasSpace, isSpace;

    wasSpace = isSpace = 0;

    while ((c = getchar()) != EOF){
        isSpace = (c == '\t' || c == '\n' || c == ' ');  

        if(!wasSpace && isSpace){
            putchar(' ');
        }
        else if(!isSpace){
            putchar(c);
        }

        wasSpace = isSpace;
    }
}
