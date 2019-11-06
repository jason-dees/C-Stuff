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
#include "../Shared/getword.h"

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int isnotnoise(char *);

int main(){
    struct tnode *root;
    char word[MAXWORD];
    int line = 1;

    root = NULL;
    while(getword(word, MAXWORD) != EOF){
        int notnoise = isnotnoise(word);
        printf("%d %s\n", notnoise, word);
        if(isalpha(word[0]) && notnoise){
            root = addtree(root, word, line++);
        }
    }
    treeprint(root);
    return 0;
}

int isnotnoise(char *word){
    return strcmp(word, "the") != 0 
        && strcmp(word, "and") != 0
        && strcmp(word, "a") != 0
        && strcmp(word, "but") != 0;
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