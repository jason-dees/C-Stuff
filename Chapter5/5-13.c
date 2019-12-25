#include <stdio.h>
#include <string.h>
#include "readlines.h"

#define MAXLINES 1000
#define TABLENGTH 4
/*
page 118
Write the program tail, which prints the last n lines of its input. By default,  n is 10, let us say, but it can be 
changed by an optional argument, so that
    tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the input or value of n. Write 
the program so it makes the best use of available storage; lines should be stored as in the sorting pgoram of 
section 5.6, not in a two dimensional array of fixed size.
*/

void tail(int taillength, char *lineptr[], int len);

char *lineptr[MAXLINES];
int main(int argc, char *argv[]){
    int taillength = 10;
    int nlines;

    while(--argc > 0 && (*++argv)[0] == '-'){
        taillength = atoi(*argv) * -1;
    }
    if(taillength == 0){
        taillength = 0;
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        if(nlines > 0){
            tail(taillength, lineptr, nlines);
        }
        else{
            printf("No lines to print \n");
        }
        return 0;
    }

}
void tail(int taillength, char *lineptr[], int len){
    int i = 0;
    while(taillength-- > 0 && i < len ){
        printf("tail: %s\n", lineptr[i++]);
    }
}