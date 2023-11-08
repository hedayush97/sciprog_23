#include <stdio.h>

int main(void){

    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];
    int i, j, k; //Loop indices

    //Initialize A, B and C
    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            A[i][j] = i+j;
        }
    }

    for (i=0; i<p; i++){
        for (j=0; j<q; j++){
            B[i][j] = i-j;
        }
    }

    for (i=0; i<n; i++){
        for (j=0; j<q; j++){
            C[i][j] = 0.0;
        }
    }

    //Perform matrix multiplication
    matmult(n, p, q, A, B, C);

    //Print out the matrices
    printf("\nThis is matrix A:\n");
    for (i=0; i<n; i++){
        for (j=0; j<p; j++){
            printf("%3.0f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nThis is matrix B:\n");
    for (i=0; i<p; i++){
        for(j=0; j<q; j++){
            printf("%3.0f ", B[i][j]);
        }
        printf("\n");
    }
    printf("\nThis is matrix C:\n");
    for (i=0; i<n; i++){
        for(j=0; j<q; j++){
            printf("%3.0f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}