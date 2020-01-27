#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as 
found in argv[0].
*/

int main(int argc, char *argv[]){
    int c;
    int (*action)(int c) = (strchr(argv[0], 'u') != NULL ? toupper : tolower);
    while((c = getchar()) != EOF)
        putchar(action(c));
    return 0;
}