#include <stdio.h>
#include <math.h>
/*
page 49
Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
*/

unsigned rightrot(unsigned x, int n);

int main(){
	//000110
	printf("%d\n", rightrot(6, 2));
	//001000
	printf("%d\n", rightrot(8, 1));
	//001001
	printf("%d\n", rightrot(9, 1));
	//001010
	printf("%d\n", rightrot(10, 1));
	printf("%d\n", rightrot(32, 2));
}

unsigned rightrot(unsigned x, int n){
	int max = 5;
	while(max <= n){
		n -= max;
	}

	//get left n bits and shift left max-n spaces
	unsigned rightRots = (x & ~(~0 << n)) << (max - n + 1);

	unsigned shiftedX = x >> n;
	//& n bits with shifted x

	return shiftedX | rightRots;
}
