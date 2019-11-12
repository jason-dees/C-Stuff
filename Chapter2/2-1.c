#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
/*
Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing 
appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges 
of the various floating-point types.
*/

int printUnsignedRange(char prefix[], int size);
int printSignedRange(char prefix[], int size);

int main(){
    char       c = 'a';
    int        i = 2;
    float      f = 5.1F;
    double     d = 8.4;
    short int  s = 6;
    long int   l = 8L;
    signed int si = -2;
    signed char sc = -2;

    printUnsignedRange("Unsigned char", sizeof(c));
    printUnsignedRange("Unsigned int", sizeof(i));
    printUnsignedRange("Unsigned float", sizeof(f));
    printUnsignedRange("Unsigned double", sizeof(d));
    printUnsignedRange("Unsigned short", sizeof(s));
    printUnsignedRange("Unsigned long", sizeof(l));
    printSignedRange("Signed int", sizeof(si));
    printSignedRange("Signed char", sizeof(sc));
    
}

int printUnsignedRange(char prefix[], int size){
    size = size * 8;
    double topRange = pow(2.0, size) - 1;
    
    printf("%s: 0 to %.0f\n", prefix, topRange);
    return 0;
}

int printSignedRange(char prefix[], int size){
    size = size * 8 - 1;
    double topRange = pow(2.0, size);
    
    printf("%s: %.0f to %.0f\n", prefix, (-1 * topRange), topRange - 1);
    return 0;
}
