#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sieben(int*);

int main() {
    int *pi = 3;

    printf("pi: %0X \n", pi);
    printf("&pi: %0X \n", &pi);
    printf("*pi: %i \n", *pi);
}

void sieben (int *aptr) {
    int seven = 7;
    *aptr = seven;
}