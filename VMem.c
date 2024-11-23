#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define PAGE_SIZE 4096 // 4 KiB of memory 

void main() {
    int * ptr;
    ptr = malloc(PAGE_SIZE);
    if (ptr = NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(EXIT_FAILURE);
    }

    printf("The virtual memory address starts at : %p\n", &ptr);
    free(ptr);
}
