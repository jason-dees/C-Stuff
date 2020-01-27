#include <stdio.h>
#include <stdarg.h>
/* minprintf: minimal printf wiht variable arguments list */
void minprintf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt);
    for(p = fmt; *p; p++){
        // check *p and *(p+1) for 2 character stuff
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);/* clean up when done */
}
/*
page 156
Revise minprintf to handle more of the other facilities of printf.
*/

int main(int argc, char *argv[]) {
    printf("%.1s", "hello, world");
}