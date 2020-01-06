#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readlines.h"
/*
page 121
Add a field-handling capability, so sorting may be done on fields within lines, each field sorted according to an
independent set of options. (the index for this book was sorted with -df for the index category and -n for the page
numbers.)
*/

#define MAXLINES 5000
char *lineptr[MAXLINES];

void writelines(char *lineptr[], int nlines);
void reverselines(char *lineptr[], int nlines);

void qSort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int dircmp(char *, char *);
int maincmp(char *, char *);
int strcasecmp_custom(char *, char *);
int strcmp_custom(char *, char *);

int pos1 = 0;
int pos2 = 0;

int direction = 1;
int numeric = 0;
int ignorecase = 0;
int directoryorder = 0;

int main(int argc, char *argv[]){
    int nlines, c;
    while((--argc>0) && (((c = (*++argv)[0])=='-')||(c=='+'))){
        if (c=='-' && !isdigit(*(argv[0]+1))){
            while((c = *++argv[0])){
                switch(c) {
                    case 'd':
                        directoryorder = 1;
                        break;
                    case 'f':
                        ignorecase = 1;
                        break;
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        direction = 0;
                        break;
                    default:
                        break;
                }
            }
        }
        else if (c == '-'){
            pos2 = atoi(argv[0]+1);
        }
        else if(c == '+'){
            pos1 = atoi(argv[0]+1);
        }
    }
    int (*comparer)(void*, void*) = maincmp;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qSort((void **) lineptr, 0, nlines -1, comparer);
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
void substr(char *s, char *out);
int maincmp(char *s1, char *s2){
    int (*comparer)(void*, void*) = (numeric ? numcmp: ignorecase ? strcasecmp_custom : strcmp_custom);
    if(pos2 > 0){
        char out1[100], out2[100];
        substr(s1, out1);
        substr(s2, out2);
        return comparer(out1, out2);
        //substring
    }
    else{
        return comparer(s1, s2);
    }
}
void substr(char *s, char *out)
{
    int i, j, len;
    extern int pos1, pos2;

    len = strlen(s);
    if(pos2 > 0 && len > pos2)
        len = pos2;
    for(j = 0, i = pos1; i < len; i++, j++){
        out[j] = s[i];
    }
    out[j] = '\0';
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

void strclean(char *s){
    int c, i, j;
    i = 0;
    j = 0;
    while((c = s[i++]) != '\0'){
        if(c == ' ' || (c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            s[j++] = c;
        }
        else{
        }
    }
    s[j] = '\0';
}

#include <stdlib.h>
int numcmp(char *s1, char *s2){
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

void strclean(char *s);
void strcleancpy(char *dest, char *src);
int dircmp(char *s1, char *s2){
    strclean(s1);
    strclean(s2);
    return strcmp(s1,s2);
}
void strcleancpy(char *dest, char *src){
    printf("%s\n", dest);
    while((*src) != '\0'){
        if(*src == ' ' || (*src >= 'A' && *src <='Z') || (*src >= 'a' && *src <= 'z') || (*src >= '0' && *src <= '9')){
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';
}

void writelines(char *lineptr[], int nlines){
    int i = 0;
    for(i = 0; i< nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}
void reverselines(char *lineptr[], int nlines){
    while(--nlines > -1){
        printf("%s\n", lineptr[nlines]);
    }
}

int strcasecmp_custom(char *s1, char *s2){
    if(directoryorder == 1){
        char *clean1 = alloc(strlen(s1));
        char *clean2 = alloc(strlen(s2));
        strcleancpy(clean1, s1);
        strcleancpy(clean2, s2);
        return strcasecmp(clean1, clean2);
    }
    return strcasecmp(s1,s2);
}
int strcmp_custom(char *s1, char *s2){
    if(directoryorder == 1){
        char *clean1 = alloc(strlen(s1));
        char *clean2 = alloc(strlen(s2));
        strcleancpy(clean1, s1);
        strcleancpy(clean2, s2);
        return strcmp(clean1, clean2);
    }
    return strcmp(s1,s2);
}