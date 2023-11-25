#include <stdio.h>
#include <stdlib.h>

// Function declaration/prototype
// Input arguments: Fn-1 and Fn-2
// On exit: Fn and Fn-1
void fibonacci(int *a, int *b);

int main() {
    int n, i;
    int f0 = 0, f1 = 1;

    // enter information from the user
    printf("Enter a positive integer\n");
    scanf("%d", &n);

    if (n < 1) {
        printf("The number is not positive.\n");
        exit(1);
    }

    // Print the fibonacci series
    printf("The Fibonacci sequence is: \n");
    printf("%d, %d, ", f0, f1);

    // Calculating the Fibonacci sequence from 2
    for (i = 2; i < n; i++) {
        fibonacci(&f1, &f0);
        printf("%d, ", f1);

        if ((i + 1) % 10 == 0){
            printf("\n");
        }
    }

    return 0;
}

// Function for fibonacci
void fibonacci(int *a, int *b) {
    int next;
    next = *a + *b;
    *b = *a;
    *a = next;
}
