#include <stdio.h>

int main()
{
    unsigned int num; 
    scanf("%u", &num);

    unsigned char b1 = (num & 0xFF);
    unsigned char b2 = (num >> 8) & 0xFF;
    unsigned char b3 = (num >> 16) & 0xFF;
    unsigned char b4 = (num >> 24) & 0xFF;


    printf("Extracted Bytes: \n");
    printf("b1: %u\n", b1);
    printf("b2: %u\n", b2);
    printf("b3: %u\n", b3);
    printf("b4: %u\n", b4);
    return 0;

}
