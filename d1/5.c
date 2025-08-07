
#include <stdio.h>

int is_little_endian() {
    unsigned int x = 1;
    return *((char*)&x);
}

unsigned int swap_endian(unsigned int num) {
    return ((num >> 24) & 0xFF) |
           ((num >> 8) & 0xFF00) |
           ((num << 8) & 0xFF0000) |
           ((num << 24) & 0xFF000000);
}

int main() {
    unsigned int num;
    printf("Enter a 4-byte integer: ");
    scanf("%u", &num);

    // Check endianness
    if (is_little_endian())
        printf("\nHost machine is Little Endian.\n");
    else
        printf("\nHost machine is Big Endian.\n");

    // Print each byte
    unsigned char *ptr = (unsigned char*)&num;
    printf("\nBytes of the number (from lowest address to highest):\n");
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: %02X\n", i, ptr[i]);
    }

    // Convert endianness
    unsigned int swapped = swap_endian(num);
    printf("\nNumber after endianness conversion: %u\n", swapped);
    printf("Bytes after conversion (from lowest address to highest):\n");
    unsigned char *sptr = (unsigned char*)&swapped;
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: %02X\n", i, sptr[i]);
    }

    return 0;
}