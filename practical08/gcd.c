#include<stdio.h>

// Function for gcd interation
int gcd_iteration(int a, int b){
    int temp;
    while (b!=0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

// Functionf gcd recursive
int gcd_recursive(int a, int b){
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd_recursive(b, a%b);
    }
}


 // Call both the functions
int main(void){
    int a = 5;
    int b = 25;
    
    int ans_r = gcd_recursive(a, b);
    int ans_i = gcd_iteration(a, b);

    // Print the answers from the functions
    printf("Using iteration, we get the answer: %d\n", ans_i);
    printf("Using recursion, we get the answer: %d\n", ans_r);
    return 0;
}