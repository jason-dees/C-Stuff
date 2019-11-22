#include <stdio.h>
#include "stack.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: stack is full!! %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    return 0.0;
}

void printtop()
{
    printf("%f\n", val[sp - 1]);
}

void duplicate(double copy[])
{
    int i = 0;
    while (i < sp)
    {
        copy[i++] = val[i];
    }
}

void swap()
{
    double first = pop();
    double second = pop();

    push(first);
    push(second);
}

void clear()
{
    while (sp > 0)
    {
        pop();
    }
}
