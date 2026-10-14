#include <stdio.h>
#include <math.h>

int main(void) {
    const double EPS = 1e-9;       // допуск для порівняння дійсних чисел
    const double LEFT_BOUND = -2.0;
    const double RIGHT_BOUND = 2.0;
    const double CONST_VALUE = 4.0;

    double x_start, x_end, step;

    printf("Enter Xstart: ");
    if (scanf("%lf", &x_start) != 1) {
        printf("Error: Xstart must be a number.\n");
        return 1;
    }
    printf("Enter Xend: ");
    if (scanf("%lf", &x_end) != 1) {
        printf("Error: Xend must be a number.\n");
        return 1;
    }
    printf("Enter step dX: ");
    if (scanf("%lf", &step) != 1) {
        printf("Error: dX must be a number.\n");
        return 1;
    }

    // Валідація: Xstart < Xend та dX > 0
    if (x_start >= x_end || step <= 0) {
        printf("Error: require Xstart < Xend and dX > 0.\n");
        return 1;
    }

    printf("\n%10s | %12s\n", "X", "Y(X)");
    printf("-----------+-------------\n");

    // Кількість кроків рахуємо наперед, щоб уникнути накопичення похибки
    long steps = (long)floor((x_end - x_start) / step + EPS);

    for (long i = 0; i <= steps; i++) {
        double x = x_start + i * step;
        double y;

        if (x <= LEFT_BOUND) {
            y = CONST_VALUE;
        } else if (x < RIGHT_BOUND) {
            y = x * x - 1.0;
        } else {
            y = 2.0 * x;
        }

        printf("%10.2f | %12.4f\n", x, y);
    }

    return 0;
}