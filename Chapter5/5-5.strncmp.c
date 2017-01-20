#include <stdio.h>

int strncmp(char *, char *, size_t);

int main(){
    char amessage[] = "fgdfd";
    char bmessage[] = "fgli";
    
    printf("%d\n", strncmp(amessage, bmessage, 2));

    
    printf("%d\n", strncmp(amessage, bmessage, 4));
}

int strncmp(char *s, char *t, size_t n){
    int count = 0;
    for( ; *s == *t && count < n; s++, t++, count++){
        if(*s == '\0'){
            return 0;
        }
    }
    if(count == n){
        return *--s - *--t;
    }
    return *s - *t;
}