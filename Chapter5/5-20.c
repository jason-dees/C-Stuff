#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Shared/getch.h"
/*
page 126
Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
*/

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, TYPE};

void dcl(void);
void dirdcl(void);

int gettoken(void);
void clearbuff();
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int isvalid = 0;
int main(){
    int type;
    char temp[MAXTOKEN];

    while(gettoken() != EOF){
        isvalid = 1;
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if(tokentype == '\n' && !isvalid){
            clearbuff();
            printf("There was an issue with your input: %s\n", token);
            printf("out: %s\n", out);
            out[0] = '\0';
            token[0] = '\0';
            name[0] = '\0';
            datatype[0] = '\0';
            isvalid = 1;
        }
        else{
            printf("%s: %s %s\n", name, out, datatype);
        }
    }

    return 0;
}

void dcl(void){
    int ns;

    for(ns = 0; gettoken() == '*';){
        ns++;
    }
    dirdcl();
    while(ns-- > 0){
        strcat(out, " pointer to");
    }
}

void dirdcl(void){
    int type;

    if(tokentype == '('){
        dcl();
        if(tokentype != ')' && tokentype != TYPE){
            isvalid = 0;
            printf("missing ')'\n");
        }
        else if(tokentype == TYPE){
            strcat(out, " taking");
            strcat(out, token);
        }
    }
    else if(tokentype == NAME){
        strcpy(name, token);
    }
    else{
        isvalid = 0;
        printf("expected name or (dcl)\n");
        return;
    }

    while((type = gettoken()) == PARENS || type == BRACKETS){
        if(type == PARENS){
            strcat(out, " function returning");
        }
        else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int gettoken(void){
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    while( (c = getch()) == ' ' || c == '\t'){
        ;
    }
    if(c == '(') {
        if( (c = getch()) == ')' ) {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else if(isalpha(c)){//is int or char or whatever
            printf("is alpha\n");
            for( *p++ = c; isalnum(c = getch()); ){
                *p++ = c;
            }
            *p = '\0';
            ungetch(c);
            return tokentype = TYPE;
        }
        else{
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if( c == '[' ){
        for( *p++ = c; ( *p++ = getch()) != ']';){
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if( isalpha(c) ){
        for( *p++ = c; isalnum(c = getch()); ){
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else{
        return tokentype = c;
    }
}