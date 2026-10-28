#include <stdio.h>

#define MAX_LEN 100
#define BUFFER_SIZE (MAX_LEN + 1)  // правило N + 1 байт під '\0'

int main(void) {
    char str[BUFFER_SIZE];

    printf("Enter text (max %d chars): ", MAX_LEN);
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: input failed.\n");
        return 1;
    }

    // Ручне покрокове сканування: read - індекс читання, write - індекс запису
    int read = 0;
    int write = 0;
    int prev_space = 0;  // чи був попередній символ пробілом

    while (str[read] != '\0' && str[read] != '\n') {
        if (str[read] == ' ') {
            // Записуємо лише перший пробіл із послідовності
            if (!prev_space) {
                str[write++] = ' ';
            }
            prev_space = 1;
        } else {
            str[write++] = str[read];
            prev_space = 0;
        }
        read++;
    }
    str[write] = '\0';  // завершальний нуль-термінатор

    printf("Result: \"%s\"\n", str);

    return 0;
}