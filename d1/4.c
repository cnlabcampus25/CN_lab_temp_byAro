/*
write a c program  to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number and print the same. 
struct pkt{
    char ch1;
    char ch2[2];
    char ch3;
};
*/

#include <stdio.h>
#include <string.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    // Split the integer into 4 bytes
    struct pkt p;
    p.ch1 = (num >> 24) & 0xFF;
    p.ch2[0] = (num >> 16) & 0xFF;
    p.ch2[1] = (num >> 8) & 0xFF;
    p.ch3 = num & 0xFF;

    printf("\nContents of structure members:\n");
    printf("ch1: %d\n", (unsigned char)p.ch1);
    printf("ch2[0]: %d\n", (unsigned char)p.ch2[0]);
    printf("ch2[1]: %d\n", (unsigned char)p.ch2[1]);
    printf("ch3: %d\n", (unsigned char)p.ch3);

    // Aggregate to form the original number
    int agg = ((unsigned char)p.ch1 << 24) |
              ((unsigned char)p.ch2[0] << 16) |
              ((unsigned char)p.ch2[1] << 8) |
              ((unsigned char)p.ch3);

    printf("\nAggregated number: %d\n", agg);
    return 0;
}
