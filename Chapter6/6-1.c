/*
page 136
Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. 
Write a better verions.
*/
struct key {
    char *word;
    int count;
} keytab[] = {
    "#define", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../Shared/getch.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
int isvalidchar(char);

int main(){
    char word[MAXWORD];
    struct key *p;
    int isInComment = 0;

    while(getword(word, MAXWORD) != EOF){
        if(isvalidchar(word[0])){
            printf("%s\n", word);
            if(isInComment == 0 && strcmp(word,"/*") == 0){
                isInComment = 1;
            }
            else if(isInComment == 1 && strcmp(word,"*/") == 0){
                isInComment = 0;
            }
            if((p = binsearch(word, keytab, NKEYS)) != NULL && isInComment == 0){
                p->count++;
            }
        }
    }
    for(p = keytab; p < keytab + NKEYS; p++){
        if(p->count > 0){
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;
}

int isvalidchar(char c){
    return isalpha(c) || c == '#' || c == '_' || c == '/' || c == '*';
}

struct key *binsearch(char *word, struct key *tab, int n){
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while(low < high){
        mid = low + (high - low) / 2;
        if((cond = strcmp(word, mid->word)) < 0){
            high = mid;
        }
        else if(cond > 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return NULL;
}

#include <ctype.h>

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while(isspace(c = getch())){
        ;
    }
    if(c != EOF){
        *w++ = c;
    }
    if(!isvalidchar(c)){
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++){
        if(!isvalidchar(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}