#include <stdio.h>
#include <math.h>

double geometricSeriesSum(double a, double r, int n) {
    if (r == 1) {
        return a * n;
    } else {
        return a * (1 - pow(r, n + 1)) / (1 - r);
    }
}

int main() {
    int n_values[] = {10000, 500, 100};
    double a_values[] = {2.0, 0.01, 0.0001};
    double r_values[] = {0.01, 1.1, 2.0};

    for (int i = 0; i < 3; i++) {
        int n = n_values[i];
        double a = a_values[i];
        double r = r_values[i];

        double sum = 0.0;

        for (int j = 1; j <= n; j++) {
            sum += a * pow(r, j - 1);
        }

        double formula_result = geometricSeriesSum(a, r, n);

        printf("For n=%d, a=%.2f, r=%.2f:\n", n, a, r);
        printf("Summation result: %.2f\n", sum);
        printf("Formula result: %.2f\n", formula_result);
        printf("Difference: %.2f\n\n", sum - formula_result);
    }

    return 0;
}