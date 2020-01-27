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
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                break;
            case '.'://total length
                break;
            case '-'://pad end with spaces
                break;
            case 'c':
                ival = va_arg(ap, int);
                printf("%c", ival);
                break;
            case 'd':
            case 'i':
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
    char *indexStr = "1234567890";
    printf("1 %-5.10s:\n", indexStr);
    printf("2 %-15s:\n", indexStr);
    printf("3 %-15d:\n", 5);
    printf("4 %-10.5d:\n", 5);
    printf("5 %10.5d:\n", 5);
    printf("6 %-10.10s:\n", indexStr);
    printf("7 %10.10s:\n", indexStr);
    printf("8 %.20s:\n", indexStr);
    printf("9 %-20s:\n", indexStr);
    printf("0 %20s:\n", indexStr);
}