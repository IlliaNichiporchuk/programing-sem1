#include <stdio.h>
#include <stdint.h>

// Прототипи функцій
uint32_t set_bit(uint32_t reg, int n);
uint32_t clear_bit(uint32_t reg, int n);
uint32_t toggle_bit(uint32_t reg, int n);
int check_bit(uint32_t reg, int n);
void print_binary(uint32_t reg);

int main(void) {
    const int SET_POS = 7;
    const int CLEAR_POS = 2;
    const int TOGGLE_POS = 15;
    const int CHECK_POS = 20;

    // Початковий стан: встановлені біти 2 та 20
    uint32_t reg = 0x00100004;

    printf("Initial   : ");
    print_binary(reg);
    printf("  (0x%08X)\n", (unsigned int)reg);

    reg = set_bit(reg, SET_POS);
    printf("Set %2d    : ", SET_POS);
    print_binary(reg);
    printf("  (0x%08X)\n", (unsigned int)reg);

    reg = clear_bit(reg, CLEAR_POS);
    printf("Clear %2d  : ", CLEAR_POS);
    print_binary(reg);
    printf("  (0x%08X)\n", (unsigned int)reg);

    reg = toggle_bit(reg, TOGGLE_POS);
    printf("Toggle %2d : ", TOGGLE_POS);
    print_binary(reg);
    printf("  (0x%08X)\n", (unsigned int)reg);

    printf("Check bit %d = %d\n", CHECK_POS, check_bit(reg, CHECK_POS));

    return 0;
}

// Встановлення біта: побітове АБО з маскою
uint32_t set_bit(uint32_t reg, int n) {
    return reg | ((uint32_t)1 << n);
}

// Скидання біта: побітове І з інверсією маски
uint32_t clear_bit(uint32_t reg, int n) {
    return reg & ~((uint32_t)1 << n);
}

// Інвертування біта: побітове XOR з маскою
uint32_t toggle_bit(uint32_t reg, int n) {
    return reg ^ ((uint32_t)1 << n);
}

// Перевірка біта: повертає 1 або 0
int check_bit(uint32_t reg, int n) {
    return (reg & ((uint32_t)1 << n)) != 0;
}

// Вивід усіх 32 бітів, групами по 8
void print_binary(uint32_t reg) {
    for (int i = 31; i >= 0; i--) {
        putchar(((reg >> i) & 1) ? '1' : '0');
        if (i % 8 == 0 && i != 0) {
            putchar(' ');
        }
    }
}