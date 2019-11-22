#include <stdio.h>
#include "getch.h"
#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
 void ungets(char s[]){
     char c;
     int i = 0;
     while((c = s[i++]) != '\0'){
     }
     while(i > -1){
         ungetch(s[i--]);
     }
 }