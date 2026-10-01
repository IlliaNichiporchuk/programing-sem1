#include <stdio.h>
#include <math.h>

int main(void) {
    const double COULOMB_K = 8.99e9;  // коефіцієнт k, Н·м²/Кл²

    double charge1;    // заряд q1, Кл
    double charge2;    // заряд q2, Кл
    double distance;   // відстань r, м

    printf("Enter charge q1 (C): ");
    if (scanf("%lf", &charge1) != 1) {
        printf("Error: q1 must be a number.\n");
        return 1;
    }

    printf("Enter charge q2 (C): ");
    if (scanf("%lf", &charge2) != 1) {
        printf("Error: q2 must be a number.\n");
        return 1;
    }

    printf("Enter distance r (m): ");
    if (scanf("%lf", &distance) != 1) {
        printf("Error: r must be a number.\n");
        return 1;
    }

    // Захист від ділення на нуль (і від'ємної відстані)
    if (distance <= 0) {
        printf("Error: distance must be greater than zero.\n");
        return 1;
    }

    // Модуль добутку зарядів, як у формулі
    double force = COULOMB_K * fabs(charge1 * charge2) / (distance * distance);

    printf("Interaction force F = %.3e N\n", force);

    return 0;
}