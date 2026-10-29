#include <stdio.h>
#include <math.h>

// Прототипи функцій
double calc_hypotenuse(double leg_a, double leg_b);
double update_average(double value);

int main(void) {
    int count;

    printf("How many triangles to process? ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Error: count must be a positive integer.\n");
        return 1;
    }

    for (int i = 1; i <= count; i++) {
        double leg_a, leg_b;

        printf("Triangle %d, enter legs a and b: ", i);
        if (scanf("%lf %lf", &leg_a, &leg_b) != 2) {
            printf("Error: legs must be numbers.\n");
            return 1;
        }
        if (leg_a <= 0 || leg_b <= 0) {
            printf("Error: legs must be greater than zero.\n");
            return 1;
        }

        double hypotenuse = calc_hypotenuse(leg_a, leg_b);
        double average = update_average(hypotenuse);

        printf("Hypotenuse = %.3f, running average = %.3f\n",
               hypotenuse, average);
    }

    return 0;
}

// Розрахунок гіпотенузи, аргументи передаються за значенням
double calc_hypotenuse(double leg_a, double leg_b) {
    return sqrt(leg_a * leg_a + leg_b * leg_b);
}

// Статичні змінні зберігають стан між викликами
double update_average(double value) {
    static double sum = 0.0;
    static int calls = 0;

    sum += value;
    calls++;

    return sum / calls;
}