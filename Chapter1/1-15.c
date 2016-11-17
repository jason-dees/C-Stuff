#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float toCelsius(float fahr);

void main(){
    float fahr, celsius;

    printf("  f      c\n");

    fahr = LOWER;
    while(fahr <= UPPER){
        celsius = toCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += STEP;
    }
}

float toCelsius(float fahr){
    return 5.0/9.0 * (fahr - 32.0);

}

