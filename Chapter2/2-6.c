#include <stdio.h>
#include <math.h>

unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main(){
	//0 indexed, of course
	printf("%d\n", setbits(0, 4, 1, 1));

}

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y){
	int offs = (1 << (p - n  )) - 1; 
	int ons = (1 << (p) ) - offs;

	x = y | (int) ons;

	return x;
}
