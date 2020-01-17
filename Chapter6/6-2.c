struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "../Shared/getword.h"
/*
page 143
Write a program that reads a C program and prints in alphabetical order each group of variable  names that are
identical in the first 6 characters, but different somewhere thereafter. Don't count words within strings and comments.
Make 6 a paramter that can be set from the command line.
*/

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
struct tnode *addtreeTake(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getWordTypeDecl(char *);
int isIgnorable(char *);
int isCommentStart(char *);
#define structword 0
#define typeword 1
#define variableword 2
#define something 200
#define commaword 250
#define parenopenword 300
#define parencloseword 350
#define bracketopenword 400
#define bracketcloseword 450
#define nothing 500
#define slash 600
#define star 650
#define semicolon 800
#define doublequoteword 900
#define singlequoteword 950

int main(int argc, char *argv[]){
    struct tnode *root ;
    char word[MAXWORD];
    int sameCharacters = 6;
    int previousWords[] = {nothing, nothing, nothing, nothing, nothing};
    int previousWordCounter = 0;
    if(argc == 2){
        sameCharacters = atoi(*++argv);
        printf("Setting sameCharacters to %d\n", sameCharacters);
    }

    root = NULL;
    int isInComment = 0;
    while(getword(word, MAXWORD) != EOF){
        int wordType = getWordTypeDecl(word);
        if(wordType == semicolon){
            previousWords[0] = nothing;
            previousWordCounter = 0;
        }
        else if(wordType == typeword){
            previousWords[previousWordCounter++] = wordType;
        }
        // else if(previousWords[0] == typeword && previousWords[1] == star){
        // }
        else if(previousWords[0] == typeword && wordType == something){
            root = addtreeTake(root, word, sameCharacters);
        }
    }
    treeprint(root);
    return 0;
}
int getWordTypeDecl(char *word){
    //How do i want to say, 'no this is a function declaration'?
    //Potentionally 4 words here ('struct', 'type', 'someFunc', '(' ))
    //Have to count for 'struct sname varName', another 3 words
    if(strcmp("struct", word) == 0){
        return structword;
    }
    if (strcmp("int", word) == 0 || strcmp("char", word) == 0)
    {
        return typeword;
    }
    if(*word == '\\'){
        return slash;
    }
    if(*word == '*'){
        return star;
    }
    if(*word == ';'){
        return semicolon;
    }
    if(*word == '('){
        return parenopenword;
    }
    if(*word == ')'){
        return parencloseword;
    }
    if(*word == '['){
        return bracketopenword;
    }
    if(*word == ']'){
        return bracketcloseword;
    }
    if(*word == '"'){
        return doublequoteword;
    }
    if(*word == '\''){
        return singlequoteword;
    }
    if(*word == ','){
        return commaword;
    }
    if(isalpha(*word)){
        return something;
    }
    return nothing;
}

struct tnode *talloc(void);

struct tnode *addtreeTake(struct tnode *p, char *w, int length){
    p = addtree(p, strndup(w, length));
    printf("%s\n", p->word);
    return p;
}

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