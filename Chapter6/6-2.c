struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../Shared/getword.h"
/*
page 143
Write a program that reads a C program and prints in alphabetical order each group of variable  names that are
identical in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments.
Make 6 a paramter that can be set from the command line.
*/

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int isVariableDecl(char *);

int main(int argc, char *argv[]){
    struct tnode *root;
    char word[MAXWORD];
    int sameCharacters = 6;
    if(argc == 2){
        sameCharacters = atoi(*++argv);
        printf("Setting sameCharacters to %d\n", sameCharacters);
    }

    root = NULL;
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}
int isVariableDecl(char *word){

}

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if(p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }
    else if(cond < 0){
        p->left = addtree(p->left, w);
    }
    else{
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p){
    if(p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}