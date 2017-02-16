struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../getword.h"

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

void rebalancetocount(struct tnode *p){
    if(p->right != NULL && p->count > p->right->count){
        swap(p, p->right);
        rebalancetocount(p);
    }
    else if(p->left != NULL && p->count < p->left->count){
        swap(p, p->left);
        rebalancetocount(p);
    }
    if(p->left != NULL){
        rebalancetocount(p->left);
    }
    else if(p->right != NULL){
        rebalancetocount(p->right);
    }
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