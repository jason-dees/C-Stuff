#include <stdio.h>
#define MAXLINE 1000
/*
page 165
Write a program to print a set of files, starting each new one on a new page, with at title and a running page count
for each file.
*/

void toStdout(FILE *fp);

int main(int argc, char *argv[]){
    int page = 1;
    FILE *fp;
    while((fp = fopen(*++argv, "r")) != NULL){
        printf("Page %d\n", page);
        toStdout(fp);
        fclose(fp);
    }
}

void toStdout(FILE *fp){
    char line[MAXLINE];
    char *lineptr = line;
    size_t lineSize = sizeof(char) * MAXLINE;
    int lineCounter = 0;
    while (getline(&lineptr, &lineSize, fp) > 0) {
        printf("%s", line);
    }
    printf("\n");
}
