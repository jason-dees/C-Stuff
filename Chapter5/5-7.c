#include <stdio.h>
#include <string.h>
/*
page 110
Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage.
*/

#define MAXLINES 5000

#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *allocp);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(){
    int nlines;
    char allocbuf[ALLOCSIZE];

    if((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0){
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }
    else{
        printf("error: input too big to sort\n");
        return 1;
    }
}

void qsort(char *v[], int left, int right){
    int i, last;

    void swap(char *v[], int i, int j);

    if(left >= right){
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for(i = left+1; i <= right; i++){
        if(strcmp(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000
int getLine(char *, int);

int readlines(char *lineptr[], int maxlines, char allocbuf[]){
    int len, nlines;
    char *p, line[MAXLEN];
    char *allocp = allocbuf;

    nlines = 0;
    while((len = getLine(line, MAXLEN)) >  0 && len > 1){
        //if input has more than max lines OR the allocp point + length of line is outside/greater than the allocated size
        if(nlines >= maxlines || allocbuf + ALLOCSIZE - allocp < len){
            return -1;
        }
        else{
            allocp += len;
            p = allocp - len;
            line[len-1] = '\0';//terminate end of line string
            strcpy(p, line);//copy line into the space allocated starting at p
            lineptr[nlines++] = p; //set array index to space allocted starting at p
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    int i;
    for(i = 0; i< nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}

int getLine(char *s, int lim){
    int c, i;
    for(i = 0; i< lim - 1 && (*s = getchar()) != EOF && *s != '\n'; ++i){
        s++;
    }
     if(*s == '\n'){
        ++i;
    }
    *(++s) = '\0';
    return i;
}