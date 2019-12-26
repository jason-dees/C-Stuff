#include <stdio.h>
#include "readlines.h"
/*
page 107
Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.
*/

int main(){
    int len;
    char line[100] = " ";

    while((len = getLine(line, 200)) > 0){
        printf("%s\n", line);
    }
}
