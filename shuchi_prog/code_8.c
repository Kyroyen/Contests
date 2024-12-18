#include <stdio.h>

// Function to find GCD (HCF) using the Euclidean method

// RECURSIVE
int gcd(int a, int b) {
    // Base case: if second number becomes 0, return the first number as GCD
    if (b == 0) {
        return a;
    }
    
    // Recursive case: call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

// ITERATIVE
int gcd_i(int a, int b) {
    // Base case: if second number becomes 0, return the first number as GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    // Recursive case: call gcd with b and the remainder of a divided by b
    return a;
}




int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Find and print the GCD (HCF)
    int result = gcd_i(num1, num2);
    printf("The HCF of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
