#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void reverselines(char *lineptr[], int nlines);

void qSort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[]){
    int nlines;
    int direction = 1;
    int numeric = 0;
    while(argc-- > 1){
        ++argv;
        if(strcmp(*argv, "-n") == 0){
            numeric = 1;
        }
        else if(strcmp(*argv, "-r") == 0){
            direction = 0;
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qSort((void **) lineptr, 0, nlines -1,
            (int (*)(void*, void*))(numeric ? numcmp: strcmp));
        if(direction){
            writelines(lineptr, nlines);
        }
        else{
            reverselines(lineptr, nlines);
        }
        return 0;
    }
    return 1;
}

void qSort(void *v[], int left, int right, int (*comp)(void *, void*)){
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right){
        return;
    }

    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++){
        if ((*comp)(v[i], v[left]) < 0){
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qSort(v, left, last - 1, comp);
    qSort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#include <stdlib.h>
int numcmp(const char *s1, const char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2){
        return -1;
    }
    else if(v1 > v2){
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0 && len > 1){
        if(nlines >= maxlines || (p = alloc(len)) == NULL){
            return -1;
        }
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    printf("normie \n");
    int i = 0;
    for(i = 0; i< nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}
void reverselines(char *lineptr[], int nlines){
    printf("reverse \n");
    while(--nlines > -1){
        printf("%s\n", lineptr[nlines]);
    }
}

int getLine(char *s, int lim){
    int i;
    //I want to refactor this
    for(i = 0; i< lim - 1 && (*s = getchar()) != EOF && *s != '\n'; i++){
        s++;
    }
    if(*s == '\n'){
        i++;
    }
    *(++s) = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp +=n;
        return allocp -n;
    }
    return 0;
}