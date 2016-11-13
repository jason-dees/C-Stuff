#include <stdio.h>

#define LOWER -32
#define UPPER 300
#define STEP 20

void main(){
    float fahr, celsius;

    printf("  f      c\n");

    celsius = LOWER;
    while(celsius <= UPPER){
        fahr = celsius * 9.0/5.0 + 32.0;
        printf("%3.1f %6.0f\n", fahr, celsius);
        celsius += STEP;
    }
}