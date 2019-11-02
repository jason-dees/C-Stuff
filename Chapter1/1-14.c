#include <stdio.h>
#define BIGGEST_CHAR 256

int main(){
    int c, i, mostChars, longestWordLoop;

    int characterCounts[BIGGEST_CHAR];

    mostChars  = 0;
    
    for(i = 0; i < BIGGEST_CHAR; ++i){
        characterCounts[i] = 0;
    } 

    while((c = getchar()) != EOF){
       ++characterCounts[c];

       if(characterCounts[c] > mostChars){
           mostChars = characterCounts[c]; // keeps track of the longest word
       }
    }
    
    for(longestWordLoop = mostChars; longestWordLoop > 0; --longestWordLoop){// Loop for the height of the histogram
        printf("%d", longestWordLoop);

        for(i = 0; i < BIGGEST_CHAR; ++i){
            if(characterCounts[i]){//only shows lenths that have words
                if(characterCounts[i] >= longestWordLoop){
                    printf(" #");
                }
                else{
                    printf("  ");
                }
            }
        } 
        putchar('\n');

    }
    printf(" ");
    for(i = 0; i < BIGGEST_CHAR; ++i){
        if(characterCounts[i]){//only shows lenths that have words
            switch(i){
                case ' ':
                    printf(" _");
                   break; 
                case '\t':
                    printf("\\t");
                   break; 
                case '\n':
                    printf("\\n");
                   break; 
                default:
                    printf(" ");
                    putchar(i);
            }
        }
    } 
    putchar('\n');
}
