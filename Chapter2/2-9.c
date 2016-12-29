#include <stdio.h>
#include <math.h>

int bitcount(unsigned x);

int main(){
	printf("%d\n", bitcount(6));
	printf("%d\n", bitcount(8));
	printf("%d\n", bitcount(9));
	printf("%d\n", bitcount(10));
	printf("%d\n", bitcount(11));
	//getbits is 101
}

int bitcount(unsigned x){
	int b;

	for(b = 0; x != 0; x &= (x -1)){
		b++;
	}

	return b;
}
