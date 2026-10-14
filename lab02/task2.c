#include <stdio.h>
#include <math.h>

int main(void) {
    const int MAX_ITERATIONS = 100000;  // Timeout Guard

    double x, eps;

    printf("Enter X (|X| < 1): ");
    if (scanf("%lf", &x) != 1) {
        printf("Error: X must be a number.\n");
        return 1;
    }
    if (fabs(x) >= 1.0) {
        printf("Error: X is outside the convergence region |X| < 1.\n");
        return 1;
    }

    printf("Enter precision eps (e.g. 1e-5): ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("Error: eps must be a positive number.\n");
        return 1;
    }

    double term = 1.0;  // a0 = X^0 = 1
    double sum = 0.0;
    int iterations = 0;

    while (fabs(term) >= eps) {
        if (iterations >= MAX_ITERATIONS) {
            printf("Warning: precision not reached in %d iterations.\n",
                   MAX_ITERATIONS);
            break;
        }
        sum += term;
        term *= x;      // a_n = a_(n-1) * X
        iterations++;
    }

    double exact = 1.0 / (1.0 - x);
    double abs_error = fabs(exact - sum);
    double rel_error = abs_error / fabs(exact);

    printf("Series sum      : %.10f\n", sum);
    printf("Exact 1/(1-X)   : %.10f\n", exact);
    printf("Absolute error  : %.3e\n", abs_error);
    printf("Relative error  : %.3e\n", rel_error);
    printf("Iterations      : %d\n", iterations);

    return 0;
}