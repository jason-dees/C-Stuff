#include <stdio.h>

void main(){
    int numberOfTabs, numberOfSpaces, numberOfNewLines, c;

    numberOfTabs = numberOfSpaces = numberOfNewLines = 0;

    while ((c = getchar()) != EOF){
        switch(c){
            case '\t':
                numberOfTabs ++;
                break;
            case '\n':
                numberOfNewLines ++;
                break;
            case ' ':
                numberOfSpaces ++;
                break;
        }

    }

    printf("Number of Tabs:      %d\n", numberOfTabs);
    printf("Number of New Lines: %d\n", numberOfNewLines);
    printf("Number of Spaces:    %d\n", numberOfSpaces);

}
