#include <stdio.h>
#include <math.h>


int main() {

    // Declaring all the variables for case selection and GP calculation
    int n, i; 
    double a, r;

    // Displaying the 3 different case information for GP
    for(i = 1; i <= 3; i++){
        printf("Case %d:\n", i);
        switch (i) {
            case 1:
                n = 10000;
                a = 2.0;
                r = 0.01;
                break;
            case 2:
                n = 500;
                a = 0.01;
                r = 1.1;
                break;
            case 3:
                n = 100;
                a = 0.0001;
                r = 2.0;
                break;
            default:

                // Printing an error message for an invalid case
                printf("Invalid case!\n");
        }

        // Calculating the GP sum using the formula
        double Sn_formula = a * (1 - pow(r, n + 1)) / (1 - r);

        // Calculating the GP sum using the function
        double Sn_summation = 0.0;
        for (int j = 0; j <= n; j++) {
            Sn_summation += a * pow(r, j);
        }

        // Displaying the selected values of n, a, and r
        printf("For n = %d, a = %.2f, r = %.4f:\n", n, a, r);

        // Displaying Sn calculated by the function (Summation)
        printf("Sn (Calculated): %.3f\n", Sn_summation);

        // Displaying Sn calculated using the formula
        printf("Sn (Formula): %.3f\n", Sn_formula);

        // Displaying the difference and comparing the two results
        printf("Difference: %.3f\n\n", Sn_formula - Sn_summation);
    
    }

    // Return 0 to indicate successful program execution
    return 0;
}


// In case1, both the calculated sum and the formula result match perfectly, with a difference of 0.000. 
// This is expected when you have a large number of terms, and the common ratio is relatively small.

// In case2, there is a significant difference between the calculated sum and the formula result, with a difference of 8192.000. 
// The discrepancy may be due to precision issues when dealing with very large numbers and a common ratio significantly greater than 1.

// In case3, there is also a substantial difference between the calculated sum and the formula result, with a difference of 34359738368.000.

// When common ratio (r) is very large and the first term (a) is very small, we will get a very huge difference.
// Whereas, when common ratio (r) is relatively small and first term (a) is large the difference comes approx to zero.