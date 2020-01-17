#define MAXWORD 100

struct tnode {
    char *word;
    int lines[MAXWORD];
    int linepos;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../Shared/getLine.h"
/*
page 143
Write a cross-referencer that prints a list of all the words in a document, and, for each word,a list of the line
numbers on which it occurs. Remove noise words like "the," "and," and so on.
*/

struct tnode *addtreeLine(struct tnode *, char *, int);
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int isnotnoise(char *);

int main(){
    struct tnode *root;
    char line[MAXWORD];
    int lineCount = 1;
    int len = 0;

    root = NULL;
    while((len = getLine(line, MAXWORD)) > 0){
        root = addtreeLine(root, line, lineCount++);
    }
    treeprint(root);
    return 0;
}


int isnotnoise(char *word){
    return strcmp(word, "the") != 0
        && strcmp(word, "and") != 0
        && strcmp(word, "a") != 0
        && strcmp(word, "or") != 0
        && strcmp(word, "nor") != 0
        && strcmp(word, "but") != 0;
}

struct tnode *addtreeLine(struct tnode *p, char *l, int line){
    char word[MAXWORD];
    while(*l != '\0'){
        while(isspace(*l++)){
            ;
        }
        l--;
        int lim = MAXWORD;
        char *wp = (char *)word;
        while(--lim > 0 && isalpha(*wp++ = *l++)){
        }
        l--;
        *--wp = '\0';
        if(isnotnoise(wp) && word[0] != '\0'){
            p = addtree(p, word, line);
        }
    }
    return p;
}
struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *w, int line){
    int cond;
    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->lines[0] = line;
        p->linepos = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0){
        p->lines[p->linepos++] = line;
    }
    else if(cond < 0){
        p->left = addtree(p->left, w, line);
    }
    else{
        p->right = addtree(p->right, w, line);
    }
    return p;
}

void treeprint(struct tnode *p){
    int i = 0;
    if(p != NULL){
        treeprint(p->left);
        printf("%s ", p->word);
        while(p->lines[i]>0){
            printf("%4d ", p->lines[i++]);
        }
        putchar('\n');
        treeprint(p->right);
    }
}

#include <stdlib.h>

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}