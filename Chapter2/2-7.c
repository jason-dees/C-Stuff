#include <stdio.h>
#include <math.h>
/*
page 49
Write a function invert(x,p,n) that returns x with the n bits that being at position p inverted, leaving the others 
unchanged.
*/

unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);

int main(){
	//invert of 1000
	printf("%d\n", invert(8, 3, 2));
	printf("%d\n", invert(12, 3, 2));
	printf("%d\n", invert(13, 3, 1));
	printf("%d\n", invert(15, 3, 2));
	//getbits is 101
}

unsigned invert(unsigned x, int p, int n){
	//Assuming that p isn't a really huge number that we can't get bits for
	printf("---------\n");
	printf("FOR  %d\n", x);
	//Creates a bunch of ones at of length n 
	unsigned onedBits = (1 << (n)) - 1;
	printf("onedBits  %d\n", onedBits);
	//Length of left shift amount the ones to match where we want to 
	//xor/invert the bits at p through p-n
	unsigned leftShiftAmount = (p - 1);
	printf("Left Shift Amount %d\n", leftShiftAmount);
	//Creates the values to xor
	unsigned XORer = (onedBits << leftShiftAmount);
	printf("XORer %d\n", XORer);
	//^ with x
	return x ^ XORer;
}

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}
