struct nlist{
    struct nlist *next;
    char *name;
    char *defn;
};

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
page 145
Write a function undef that will remove a name and definition from the table maintained by lookup and install.
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

int main(){
    install("bB", "thingb");
    install("aa", "thinga");
    install("di", "thingd");
    struct nlist *a = lookup("bB");
    printf("bB: %s\n",a->defn);
    undef("aa");
    a = lookup("aa");
    printf("is null %d\n", a == NULL);
    a = lookup("bB");
    printf("is null %d\n", a == NULL);
}

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