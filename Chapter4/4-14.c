#include <stdio.h>

#define swap(t, x, y) t a = x; \
                      x = y; \
                      y = a;

int main(){
    int x = 1;
    int y = 2;
    swap(int, x, y);
    printf("x %d y %d \n", x, y);
}