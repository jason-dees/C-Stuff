#include <stdio.h>

#define IN  1
#define OUT 2

int main(){
    int c, isSpace;

    isSpace = OUT;

    while((c = getchar()) != EOF){

        isSpace = (c == '\t' || c == '\n' || c == ' ');

        if(isSpace){
            putchar('\n');
        }
        else{
            putchar(c);
        }

    }
}
