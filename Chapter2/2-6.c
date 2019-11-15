#include <stdio.h>
#include <math.h>
/*
page 49
Write a function setbits(x,p,y,y) that returns x with the n bits that begin at position p set to the rightmost n bits 
of y, leaving the other bits unchanged.
*/

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main(){
	//5 = 0101
	//6 = 0110
	//7 = 0111
	//8 = 1000
	//9 = 1001
	//10 = 1010
	//11 = 1011
	//12 = 1100
	//13 = 1101
	//15 = 1111
	printf("%d\n", setbits(9, 3, 2, 11));
}

unsigned getbits(unsigned x, int p, int n){
	printf("from %d get %d bits from position %d \n", x, n, p);
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	int yp = getbits(y, n-1, n);
	printf("left shift yp %d over %d bits = ", yp, p-1);
	yp = yp << (p-1);
	printf("%d\n", yp);
	unsigned zeroedBits = getbits(x, p, n);
	printf("%d\n", zeroedBits);
	zeroedBits = zeroedBits << (p - 1);
	printf("%d\n", zeroedBits);
	x = x & ~zeroedBits;
	printf("%d\n", x);
	return x | yp;
}
