#include <stdio.h>
#include <math.h>
/*
page 49
Write a function setbits(x,p,y,y) that returns x with the n bits that begin at position p set to the rightmost n bits 
of y, leaving the other bits unchanged.
*/

unsigned setbits(int x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main(){
	//0 indexed, of course
	//x = 0100
	//y = 0001
	//9 = 1001
	printf("%d\n", setbits(4, 4, 1, 1));
}

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(int x, int p, int n, int y){
	//god everything i did was wrong!!!
	int offs = (1 << (p - n)) - 1; 
	int ons  = (1 << (p)) - offs;

	x = y | (int) ons;

	return x;
}
