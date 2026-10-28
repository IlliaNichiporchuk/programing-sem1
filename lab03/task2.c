#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main(void) {
    const int MIN_VALUE = -9;
    const int MAX_VALUE = 9;
    int matrix[ROWS][COLS];
    int positive_count[ROWS] = {0};  // вектор результатів

    srand((unsigned int)time(NULL));

    // Row-Major Order: зовнішній цикл по рядках, внутрішній по стовпцях
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Підрахунок додатних елементів у кожному рядку
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > 0) {
                positive_count[i]++;
            }
        }
    }

    printf("\nPositive elements per row:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: %d\n", i + 1, positive_count[i]);
    }

    return 0;
}