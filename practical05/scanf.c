#include <stdio.h>

int main(void) {
    int i, ierr;
    double a;

    // Enter information from user
    printf("Enter an int and double\n");
    scanf("%d %lf",&i,&a);

    ierr = scanf("%d %lf", &i, &a);
    if(ierr!=2) printf("Problem with input");

    return 0;
}
