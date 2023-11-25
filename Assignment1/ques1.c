#include <stdio.h>

// Writing a function to calculate the determinant of a 3x3 matrix
double det_3x3(double mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
           mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
           mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

int main() {
    int i, j, k;
    int n = 4;
    double matrix[4][4];

    // Create the 4x4 matrix given in the question
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = 1.0 / (i + j + 1);
        }
    }

    // Print the 4x4 matrix
    printf("Generated Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.3lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the determinant of the 4x4 matrix using Cramer's rule
    double determinant = 0.0;
    double submatrix[3][3];

    for (i = 0; i < n; i++) {
        
        // Create the submatrix by removing the first row and the i-th column
        for (j = 1; j < n; j++) {
            int sub_col = 0;
            for (k = 0; k < n; k++) {
                if (k != i) {
                    submatrix[j - 1][sub_col] = matrix[j][k];
                    sub_col++;
                }
            }
        }

        // Calculate the determinant of the submatrix
        double sub_det = det_3x3(submatrix);

        // Apply Cramer's rule to the main determinant
        if (i % 2 == 0) {
            determinant += matrix[0][i] * sub_det;
        } else {
            determinant -= matrix[0][i] * sub_det;
        }
    }

    printf("\nDeterminant of the 4x4 matrix: %.10f\n", determinant);

    // Return 0 shows successful compilation of the code
    return 0;
}