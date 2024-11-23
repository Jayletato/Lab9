#include <stdlib.h>
#include <stdio.h>

void main() {
    int * ptr;
    ptr = (int *) malloc(100 * sizeof(int));
    if (ptr = NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(EXIT_FAILURE);
    }

    free(ptr);
}
