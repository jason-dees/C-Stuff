#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/*
page 165
Write a program  to compare two files, printing the first line where they differ.
*/

//use fgets to get each line in the files at the same time and strcmp them
int main(int argc, char *argv[]){
    if(argc == 1){
        printf("No file arguments. Need 2.\n");
        return 0;
    }
    else if(argc == 2){
        printf("Only 1 file argument. Need 2.\n");
        return 0;
    }

    FILE *fpOne = fopen(*++argv, "r");
    if(fpOne == NULL){
        fprintf(stderr, "File %s was not found\n", *argv);
    }
    FILE *fpTwo = fopen(*++argv, "r");
    if(fpTwo == NULL){
        fprintf(stderr, "File %s was not found\n", *argv);
    }
    if(fpTwo == NULL || fpOne == NULL){ return 0; }
    char lineOne[MAXLINE];
    char lineTwo[MAXLINE];
    int counter = 0;
    int eofOne = 0, eofTwo = 0, linesSame = 0;
    do {
        //I want all of these actions to complete before  exiting the loop
        eofOne = (fgets(lineOne, MAXLINE, fpOne) == NULL);
        eofTwo = (fgets(lineTwo, MAXLINE, fpTwo) == NULL);
        linesSame = strcmp(lineOne, lineTwo) == 0;;
        counter++;
    } while(eofOne == 0 && eofTwo == 0 && linesSame == 1);

    if(eofOne == 1){
        printf("Reached end of 1st file\n");
    }
    if(eofTwo == 1){
        printf("Reached end of 2nd file\n");
    }
    if(linesSame == 0){
        printf("lines differ at %d \n", counter);
        printf("1st File: %s\n", lineOne);
        printf("2nd File: %s\n", lineTwo);
    }
    else if(linesSame == 1 && eofOne == eofTwo == 1){
        printf("Files appear to be the same\n");
    }
    fclose(fpOne);
    fclose(fpTwo);

    return 0;
}
