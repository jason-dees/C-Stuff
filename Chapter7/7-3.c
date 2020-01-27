#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define LPAD 0
#define RPAD 1
#define PAD 2
#define TRIM 3
/* minprintf: minimal printf wiht variable arguments list */
void minprintf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt);
    int trim = 0, rpad = 0, lpad = 0, printedchars = 0;
    int numtype = LPAD; //also min length?
    int hitPercent = 0;
    for(p = fmt; *p; p++){
        if(*p != '%' && hitPercent == 0) {
            putchar(*p);
            continue;
        }
        hitPercent = 1;
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
                if(numtype == TRIM){
                    trim = trim*10 + atoi(p);
                }
                else if(numtype == LPAD) {
                    lpad = lpad*10 + atoi(p);
                }
                else if(numtype == RPAD) {
                    rpad = rpad*10 + atoi(p);
                }
                p--;
                break;
            case '.':
                //(string) denotes characters from string to take
                //(int) denotes pad front with 0s until length is met
                numtype = TRIM;
                p--;
                break;
            case '-':
                //(string) pad end with spaces
                //(int) pad front with 0;
                numtype = RPAD;
                p--;
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
                printf("\nt%d l%d r%d \n", trim, lpad, rpad);
                sval = va_arg(ap, char *);
                int len = strlen(sval);
                while(len++ < lpad){
                    putchar(' ');
                }
                while(*sval && printedchars<trim){
                    putchar(*sval++);
                    printedchars++;
                }
                while(printedchars++ < rpad){
                    putchar(' ');
                }
                hitPercent = 0, trim = 0, lpad = 0, rpad = 0;
                break;
            default:
                putchar(*p);
                trim = 0;
                rpad = 0;
                lpad = 0;
                printedchars = 0;
                numtype = LPAD;
                hitPercent = 0;
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
    printf("%3.5s:\n", "a");
    minprintf("%3.5s:\n", "b");
    printf("---------------\n");
    printf("%.5s:\n", indexStr);//min characters
    minprintf("%.5s:\n", indexStr);//min characters
}