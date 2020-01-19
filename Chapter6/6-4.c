struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../Shared/getword.h"
/*
page 143
Write a program that prints the distinct words in ints input sorted into decreasing order of frequency of occurrence. 
Precede each word by its count.
*/

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void rebalancetocount(struct tnode *);

int main(){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    rebalancetocount(root);
    treeprint(root);
    return 0;
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

void swap(struct tnode *, struct tnode *);
void place(struct tnode *, struct tnode *);
struct tnode *copytnode(struct tnode *);

void rebalancetocount(struct tnode *p){
    struct tnode *root;
    root = copytnode(p);
    //Still not quite right. I need to compare the right and left sides against each other too
    place(root, p->left);
    place(root, p->right);
}

void place(struct tnode *p, struct tnode *n){
    //I like this though
    if(n == NULL){
        return;
    }
    if(p->count > n->count){
        if(p->left == NULL){
            p->left = copytnode(n);
        }
        else{
            place(p->left, n);
        }
    }
    else{
        if(p->right == NULL){
            p->right = copytnode(n);
        }
        else{
            place(p->right, n);
        }
    }
}

struct tnode *copytnode(struct tnode *p){
    struct tnode *c;
    c = talloc();
    c->word = p->word;
    c->count = p->count;
    c->left = c->right = NULL;
    return c;
}

void swap(struct tnode *p, struct tnode *q){
    char wordswap[MAXWORD];
    strcpy(wordswap, p->word);
    int countswap = p->count;
    strcpy(p->word, q->word);
    strcpy(q->word, wordswap);
    p->count = q->count;
    q->count = countswap;
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