#include <stdio.h>
#define MAXLINE 1000
#define MAXPROGRAM 10000
#define FOLDAT 20
#define SLASHSTAR 1
#define STARSLASH 2
#define SINGLE '\''
/*
Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. 
Don't forget about quotes, both single and double, escape sequences and comments.
*/
//Create a stack to track this. When encountering an open, push, when encountering a corresponding close, pop.
//  Comments are not single characters
//Check for an equal number of open and close characters

int getProgram(char line[], int maxline);
int doStackStuff(char c, char p);
int push(char c);
int pop(char c);
int stackPrevious();

char stack[MAXLINE];
int stackindex;
int isincomment;

int main()
{
    int len;
    char program[MAXPROGRAM];
    isincomment = stackindex = 0;

    while ((len = getProgram(program, MAXPROGRAM)) > 0)
    {
    }
    printf("%c %d %d\n", stack[stackindex], stackindex, len);
}

int getProgram(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)
    {
        s[i] = c;
        if (c == '\\')
        {
            i++;
            //skip next character we don't care
        }
        if(!doStackStuff(c, s[i - 1])){
            return -1;
        }
    }
    return i;
}

int doStackStuff(char c, char p)
{
    int canAdd, sp;
    if (c == '/' && p == '/')
    {
        isincomment = 1;
    }
    else if (isincomment == 1 && c == '\n')
    {
        isincomment = 0;
    }

    if (isincomment == 1)
    {
        return 1;
    }
    sp = stackPrevious();
    if (sp == SLASHSTAR && p == '*' && c == '/')
    {
        pop(STARSLASH);
    }
    else if (sp == SLASHSTAR)
    {
        return 1;
    }
    else if (c == SINGLE && sp != SINGLE)
    {
        push(c);
    }
    else if (sp == SINGLE)
    {
        if(c == SINGLE){
            pop(c);
        }
    }
    else if (c == '{')
    {
        push(c);
    }
    else if (c == '}' && sp == '{')
    {
        pop(c);
    } //Previously could still explode here if the program starts with }, now just for demo purposes
    else if (c == '}' ){
        return 0;
    }
    else if (c == '(')
    {
        push(c);
    }
    else if (c == ')' && sp == '(')
    {
        pop(c);
    } //Previously could still explode here if the program starts with )
    else if (c == ')' ){
        return 0;
    }
    else if (c == '*' && p == '/')
    {
        push(SLASHSTAR);
    }
    return 1;
}

int push(char c)
{
    stack[stackindex++] = c;
    printf("pushing %c %d\n", c, stackindex);
    return stackindex;
}

int pop(char c)
{
    stackindex--;
    printf("popping %c %d\n", c, stackindex);
    return stackindex;
}

int stackPrevious()
{
    if (stackindex == 0)
    {
        return 0;
    }
    return stack[stackindex - 1];
}

//Stuff like }}}}}}}}}}}} come out ok from this and that is wrong!!