#include <stdio.h>

// Function to calculate the determinant of a 3x3 matrix
double determinant_3x3(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    int n = 4;
    double matrix[4][4];

    // Fill in the 4x4 matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1.0 / (i + j + 1);
        }
    }

    // Print the 4x4 matrix
    printf("Generated Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.3lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the determinant of the 4x4 matrix using Cramer's rule
    double determinant = 0.0;
    double submatrix[3][3];

    for (int i = 0; i < n; i++) {
        // Create the submatrix by removing the first row and the i-th column
        for (int j = 1; j < n; j++) {
            int sub_col = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    submatrix[j - 1][sub_col] = matrix[j][k];
                    sub_col++;
                }
            }
        }

        // Calculate the determinant of the submatrix
        double sub_det = determinant_3x3(submatrix);

        // Apply Cramer's rule to the main determinant
        if (i % 2 == 0) {
            determinant += matrix[0][i] * sub_det;
        } else {
            determinant -= matrix[0][i] * sub_det;
        }
    }

    printf("\nDeterminant of the 4x4 matrix: %.10f\n", determinant);

    return 0;
}
