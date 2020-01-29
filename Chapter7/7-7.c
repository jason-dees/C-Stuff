#include <stdio.h>
#include <string.h>
/*
page 165
Modify the pattern finding program of Chapter 5 to take its input from a set of named files, or, it no files are named
as arguments, from the standard input. Should the file name be printed when a matching line is found?
*/
#define MAXLINE 1000

void searchFile(FILE *, char *, char *);

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: find pattern\n");
        return 1;
    }
    FILE *fp = stdin;
    int i = 2;
    for(int i = 2; argc > i; i++) {
        fp = fopen(argv[i], "r");

        if(fp == NULL){continue;}

        searchFile(fp, argv[1], argv[i]);
    }
    if(argc == 2){
        searchFile(fp, argv[1], "stdin");
    }

    return 0;
}
void searchFile(FILE *fp, char *pattern, char *fileName){
    char line[MAXLINE];
    char *lineptr = line;
    size_t lineSize = sizeof(char)*MAXLINE;
    int lineCounter = 0;
    while(getline(&lineptr, &lineSize, fp) > 0){
        if(strstr(line, pattern) != NULL){
            printf("%10s %d: %s", fileName, lineCounter, line);
        }
        lineCounter++;
    }
    fclose(fp);
}