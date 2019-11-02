#include <stdio.h>

#define MAXWORDLENGTH 20

int main(){
    int c, i, wordLength, mostWords, longestWordLoop;

    int lengthCounts[MAXWORDLENGTH];

    wordLength = mostWords  = 0;
    
    for(i = 0; i < MAXWORDLENGTH; ++i){
        lengthCounts[i] = 0;
    } 

    while((c = getchar()) != EOF){
       if(c == ' ' || c == '\n' || c == '\t'){ //Word has ended
           if(wordLength > 0){// doesn't count two of the above characters in a row
               ++lengthCounts[wordLength];

               if(lengthCounts[wordLength] > mostWords){
                   mostWords = lengthCounts[wordLength]; // keeps track of the longest word
               }
           }
           wordLength = 0;
       }
       else{
           ++wordLength;
       }
    }
    
    for(longestWordLoop = mostWords; longestWordLoop > 0; --longestWordLoop){// Loop for the height of the histogram
        printf("%d", longestWordLoop);

        for(i = 0; i < MAXWORDLENGTH; ++i){
            if(lengthCounts[i]){//only shows lenths that have words
                if(lengthCounts[i] >= longestWordLoop){
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
    for(i = 0; i < MAXWORDLENGTH; ++i){
        if(lengthCounts[i]){//only shows lenths that have words
            printf("%2d", i);
        }
    } 
    putchar('\n');
}
