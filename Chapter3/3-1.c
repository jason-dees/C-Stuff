#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(){
    int x = 7;
    int v[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    printf("%d\n", binsearch(x, v, 10));

}

int binsearch(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = high / 2;
    while(v[low] < x){
        low ++;
    }

    while(low <= high){
        mid = (low + high) / 2;
        if(x < v[mid]){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}