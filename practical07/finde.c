/* Find e using Taylor series expansion  for e^x
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int factorial(int n);

int main(void){
    int i, order;
    double e, *terms;

    //Enter Polynomial Order
    printf("Enter the required polynomial order\n");
    if(scanf("%d", &order) !=1){
        printf("Didn't enter a number\n");
        return 1;
    }

    // Allocate space depending on n
    terms = malloc(order*sizeof(double));
    for(i=0; i<order; i++){
        terms[i] = 1.0/(double)factorial(i+1);
        printf("e terms for order %d is %1.14lf \n", i+1, terms[i]);
    }

    e = 1.0;
    for(i=0; i<order; i++){
        e = e + terms[i];
    }

    free(terms);

    printf("e is estimated as %.10lf, with difference %e\n", e, e-exp(1.0));

    return 0;
}

int factorial(int n){
    if(n<0){
        printf("Error: Negative number passed to factorial.\n");
        return(-1);
    }
    else if(n==0) {return 1;}
    else {return(n*factorial(n-1));}
}