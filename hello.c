#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sieben(int*);

int main() {
    int *result = malloc(sizeof(int));

    sieben(result);

    printf("Hallo Welt! %i \n ", *result);
}

void sieben (int *aptr) {
    int seven = 7;
    *aptr = seven;
}