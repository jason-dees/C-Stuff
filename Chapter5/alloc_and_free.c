#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;//&allocbuf[0], array name is address of 0th element

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    else{
        return 0;
    }
}

void afree(char *p){
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
        allocp = p;
    }
}