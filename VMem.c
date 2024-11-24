#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define PAGE_SIZE 4096 // 4 KiB of memory
#define OFFSET_SIZE 512 //  

int main() {
    void  *ptr;
    ptr = malloc(PAGE_SIZE);
    if (ptr = NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(EXIT_FAILURE);
    }
    printf("The virtual memory address starts at : %p\n", &ptr);

    long int virtualAddress = (long int) &ptr;

    printf("virtual_address = %#lx\n", virtualAddress);

    long int pageOffset = 

    
    
    
    
    
    
    free(ptr);

    exit(EXIT_SUCCESS);
}
