#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    const int MIN_VALUE = -50;
    const int MAX_VALUE = 50;
    int arr[SIZE];

    // Заповнення масиву псевдовипадковими числами з [-50; 50]
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    // Еталон для мінімуму: нульовий елемент
    int min_value = arr[0];
    int min_index = 0;
    int sum_positive = 0;

    for (int i = 0; i < SIZE; i++) {
        // Сума додатних елементів
        if (arr[i] > 0) {
            sum_positive += arr[i];
        }
        // Строге порівняння зберігає ПЕРШИЙ мінімальний елемент
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
    }

    // Зміна знаку всіх елементів до першого мінімального
    for (int i = 0; i < min_index; i++) {
        arr[i] = -arr[i];
    }

    printf("\nSum of positive elements: %d\n", sum_positive);
    printf("First minimum: %d at index %d\n", min_value, min_index);
    printf("Modified array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    return 0;
}