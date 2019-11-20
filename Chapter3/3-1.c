#include <stdio.h>
/*
page 58
Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a 
version with only one test inside the loop and measure the difference in run time;
*/

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