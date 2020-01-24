struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#define MAXWORD 1000

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Shared/getLine.h"
/*
page 145
Implement a simple version of the #define preprocessor (i.e. no arguments) suitable for use with C programs, based on
the routines of this section. You may also find getch and ungetch helpful.
*/

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s */
unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}

struct nlist *lookup(char *);
/* install: put(name, defn) in hashtab */
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){ //Not Found
        np = (struct nlist *)malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL) {
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else{
        free((void *) np->defn); //free previous defn
    }
    if((np->defn = strdup(defn)) == NULL){
        return NULL;
    }
    return np;
}

void undef(char *);
void undef(char *name){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){ //Not Found
        return;
    }
    else {
       hashval = hash(name);
       np = hashtab[hashval];
       if(np == NULL) return;
       do {
           hashtab[hashval] = NULL;
           if(strcmp(np->name, name) != 0){
               install(np->name, np->defn);
               //no idea if this is needed or should be here
               free((void *) np);
           }
       }
       while((np = np->next) != NULL);
    }
}

struct nlist *getdefine(char *line){
    //cycle through name
    //cycle through definition
    char name[MAXWORD];
    char defn[MAXWORD];
    struct nlist *p;
    //cycle through #define
    while (*line++ != ' ') {
        ;
    }
    //end of #define
    //Start of name
    int lim = MAXWORD;
    char *wp = (char *)name;
    while (--lim > 0 && isalpha(*wp++ = *line++))
    {
    }
    *--wp = '\0';
    //end of name
    //start of definition
    lim = MAXWORD;
    wp = (char *)defn;
    while (--lim > 0 && (*wp++ = *line++) && *line!='\n')
    {
    }
    *wp = '\0';
    //end of definition

    p->name = strdup(name);
    p->defn = strdup(defn);
    return p;
}

char *replaceDefnNames(char *iline){
    //Cycle through the line and for each word look it up in the hash
    //if it exists, copy it to the newline
    //otherwise copy characters to newline
    char fixedLine[MAXWORD];
    char word[MAXWORD];
    char *newLine = fixedLine;
    char *line = iline;

    struct nlist *found;
    while (*line != '\0')
    {
        if(isspace(*line)){
            *newLine++ = *line++;
        }
        else{
           char *wp = word;
            while(!isspace(*wp++ = *line++) && *line != '\0'){
            }
            *--wp = '\0';
            line--;
            wp = word;
            if((found = lookup(wp)) != NULL && word[0] != '\0'){
                strcpy(word, found->defn);
            }
            while((*newLine++ = *wp++) != '\0'){}
            newLine--;
        }
    }
    *++newLine = '\0';
    newLine = fixedLine;
    strcpy(iline, newLine);
    return newLine;
}

int main(){
    char line[MAXWORD];
    int lineCount = 1;
    int len = 0;

    while((len = getLine(line, MAXWORD)) > 0){
        if(strncmp("#define", line, 7) == 0){
            struct nlist *definition = getdefine(line);
            install(definition->name, definition->defn);
        }
        else{
            replaceDefnNames(line);
            printf("%s", line);
        }
    }
}
