#include <stdio.h>
#include <math.h>

int bitcount(unsigned x);

int main(){
	printf("%d\n", bitcount(6));
	printf("%d\n", bitcount(8));
	printf("%d\n", bitcount(9));
	printf("%d\n", bitcount(10));
	printf("%d\n", bitcount(11));
	//Subtracting 1 from x inverts the rightmost bits
	//x = x & (x-1) keeps the largest bits each round until all bits are 0ed
}

int bitcount(unsigned x){
	int b;

	for(b = 0; x != 0; x &= (x -1)){
		b++;
	}

	return b;
}
