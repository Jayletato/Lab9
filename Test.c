#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_address_info(void *addr) {
    // Convert address to 64-bit unsigned integer
    uint64_t virtual_address = (uint64_t)addr;

    // Extract indices and offset using bit masking and shifts
    uint64_t page_offset = virtual_address & 0xFFF;               // Last 12 bits
    uint64_t pt_index = (virtual_address >> 12) & 0x1FF;          // Next 9 bits
    uint64_t pd_index = (virtual_address >> 21) & 0x1FF;          // Next 9 bits
    uint64_t pdp_index = (virtual_address >> 30) & 0x1FF;         // Next 9 bits
    uint64_t pml4_index = (virtual_address >> 39) & 0x1FF;        // Next 9 bits

    // Print results
    printf("Virtual Address: 0x%lx\n", virtual_address);
    printf("PML4 Index: %lu\n", pml4_index);
    printf("PDP Index: %lu\n", pdp_index);
    printf("PD Index: %lu\n", pd_index);
    printf("PT Index: %lu\n", pt_index);
    printf("Page Offset: %lu\n", page_offset);
}

int main() {
    // Allocate some memory
    void *allocated_memory = malloc(4096); // Allocate a page (4 KiB)

    if (!allocated_memory) {
        perror("malloc failed");
        return 1;
    }

    // Print the address information
    print_address_info(allocated_memory);

    // Free allocated memory
    free(allocated_memory);

    return 0;
}