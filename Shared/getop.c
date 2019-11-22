#include <ctype.h>
#include <stdio.h>
#include "getop.h"
#include "getch.h"

#define NUMBER '0'
int getop(char s[])
{
    int i, c, hasMinus, hasdig;
    hasdig = hasMinus = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
    }
    //it is a negative number when it's a - and the next character is a digit
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;
    if (c == '-')
    {
        i = 1;
        c = getch();
        hasMinus = 1;
    }

    if (isdigit(c) || c == '-')
    {
        while (isdigit(s[++i] = c = getch()))
        {
        }
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
        }
    }

    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    if (hasMinus && !hasdig)
    {
        return '-';
    }

    return NUMBER;
}