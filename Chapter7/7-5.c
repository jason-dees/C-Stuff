#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 5
/*
page 159
Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf to do the input and number conversions.
*/

int main(int argc, char *argv[]) {
    //1 2 - 4 5 + * = (1-2) * (4-5)
    char operations[MAXWORD][MAXWORD];
    char buffer[MAXWORD];

    int i = 0, totalOps = 0;
    while(scanf("%s", operations[i]) > 0 && i < MAXWORD){
        i++;
        totalOps++;
    }

    for (int i=0; i<totalOps; i++){
        printf("\n%s", operations[i]);
    }

    return 0;
}