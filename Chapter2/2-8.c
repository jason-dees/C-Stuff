#include <stdio.h>
#include <math.h>

unsigned rightrot(unsigned x, int n);

int main(){
	printf("%d\n", rightrot(6, 2));
	printf("%d\n", rightrot(8, 1));
	printf("%d\n", rightrot(9, 1));
	printf("%d\n", rightrot(10, 1));
	//getbits is 101
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
