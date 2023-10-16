#include <stdio.h>
#include <math.h>

void doubled(int*);

int main() {
    int vier = 4;
    doubled(&vier);

    printf("Hallo Welt! %d \n ", vier);
}

void doubled (int *aptr) {
    *aptr = *aptr *  2;
   
}