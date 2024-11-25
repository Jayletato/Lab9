#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define PAGE_SIZE 4096 // 4 KiB of memory

int main() {
    void  *ptr;
    ptr = malloc(PAGE_SIZE);
    if (ptr = NULL) {
        printf("Memory allocation unsuccessful!\n");
        exit(EXIT_FAILURE);
    }
    printf("The virtual memory address starts at : %p\n", &ptr);

    long int virtualAddress = (long int) &ptr;

    long int pageOffset = virtualAddress & 0xFFF;
    long int ptIndex = (virtualAddress >> 12) & 0x1FF; // 0x1FF is 9 0001 1111 1111, which will derive 9 bits
    long int pdIndex = (virtualAddress >> 21) & 0x1FF;
    long int pdpIndex = (virtualAddress >> 30) & 0x1FF;
    long int pml4Index = (virtualAddress >> 39) & 0x1FF;

    printf("virtual address = %#lx\n", virtualAddress);
    printf("Page Map Level 4 Index = %lu\n", pml4Index);    
    printf("Page Directory Pointer Index = %lu\n", pdpIndex);
    printf("Page Directory Index = %lu\n", pdIndex);
    printf("Page Table Index = %lu\n", ptIndex);
    
    
    free(ptr);

    exit(EXIT_SUCCESS);
}
