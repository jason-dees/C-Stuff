#include <stdio.h>
/*
page 88
Write a recursive version of the function reverse(s), which reverses the string s in place.
*/

#define MAX 100

void readLine(char []);
void reverse(char []);

int main(){
    char s[8] = {'a','b','c','d','e', 'f', 'g', '\0'};

    reverse(s);

    printf("%s\n", s);
}


int reverser(char s[]);
int counter;

void reverse(char s[]){
    counter = 0;
    reverser(s);
}
int reverser(char s[]){
    int j = counter++;
    char at = s[j];
    if(at == '\0'){//new first character
        counter--;
        return 0;
    }
    int i = reverser(s);

    if(counter <= i || i < 0){
        return -1;
    }

    s[--counter] = s[i];
    s[i]= at;
    return i + 1;
}