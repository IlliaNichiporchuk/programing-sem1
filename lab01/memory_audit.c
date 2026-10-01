#include <stdio.h>

int main(void) {
    const unsigned char MAX_BYTE_VALUE = 255;

    // Розміри базових типів (у байтах)
    printf("char      : %zu\n", sizeof(char));
    printf("short     : %zu\n", sizeof(short));
    printf("int       : %zu\n", sizeof(int));
    printf("long      : %zu\n", sizeof(long));
    printf("long long : %zu\n", sizeof(long long));
    printf("float     : %zu\n", sizeof(float));
    printf("double    : %zu\n", sizeof(double));
    printf("void*     : %zu\n", sizeof(void *));

    // Демонстрація переповнення розрядної сітки
    unsigned char byte_test = MAX_BYTE_VALUE;
    printf("\nBefore: dec = %u, hex = 0x%02X\n", byte_test, byte_test);

    byte_test = byte_test + 1;  // 255 + 1 -> 256 mod 256 = 0
    printf("After : dec = %u, hex = 0x%02X\n", byte_test, byte_test);

    return 0;
}