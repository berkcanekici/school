/*
    CSE 108 - 4
    Name: Berkcan EKICI
    Id: 171044015
*/

#include <stdio.h>
/* Function declarations */
void russian_multiplication(unsigned int *, unsigned int *);
void multiply_polynomials(double *, double *, double *, double *, double *, double *, double *, double);

int main()
{
    // For part1:
    unsigned int num1, num2;

    printf("Please enter two numbers:\n");
    scanf("%u%u", &num1, &num2);

    printf("%u * %u = ", num1, num2);
    russian_multiplication(&num1, &num2); // Calculate processes
    
    printf("%u\n", num1);                 // Print total
    printf("Multiplier:%u\n", num2);      // Print latest multiplier
    
    // For part2:
    double a3, a2, a1, a0;
    double b3, b2, b1, b0;
    
    printf("Please enter first polynom:\n");
    scanf("%lf%lf%lf%lf", &a3, &a2, &a1, &a0);
    
    printf("Please enter second polynom:\n");
    scanf("%lf%lf%lf%lf", &b3, &b2, &b1, &b0);
    
    printf("First polynom: %.fx^3 + %.fx^2 + %.fx^1 + %.f\n", a3, a2, a1, a0);  // Print first polynom
    printf("Second polynom: %.fx^3 + %.fx^2 + %.fx^1 + %.f\n", b3, b2, b1, b0); // Print second polynom
    
    multiply_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, b0);                // Calculate processes
    
    printf("Result is: %.fx^6 + %.fx^5 + %.fx^4 + %.fx^3 + %.fx^2 + %.fx^1 + %.f\n", a3, a2, a1, a0, b3, b2, b1); // Print result polynom
}

// This function performs operations in an infinite loop.
void russian_multiplication(unsigned int *multiplicand, unsigned int *multiplier)
{
    unsigned int total = 0;

    for (;;) {
        if (*multiplier % 2 != 0) // If the multiplier is odd, it adds an addition.
            total += *multiplicand;

        if (*multiplier != 1 && *multiplier % 2 == 1) // Prints on the screen if the number is odd and not equal to 1.
            printf("%d + ", *multiplicand);        
        // If the multiplier is equal to 1, it terminates the function.
        else if (*multiplier == 1) { 
            printf("%d = ", *multiplicand);
            
            *multiplicand = total;

            return;
        }
        
        *multiplier /= 2;
        *multiplicand *= 2;
    }
}
// Polynomial calculation is done.
void multiply_polynomials(double *a3, double *a2, double *a1, double *a0, double *b3, double *b2, double *b1, double b0)
{
    // Mathematical operations are done as follows.
    double x_6 = *a3 * *b3;
    double x_5 = *a3 * *b2 + *a2 * *b3;
    double x_4 = *a3 * *b1 + *a2 * *b2 + *a1 * *b3;
    double x_3 = *a3 * b0 + *a2 * *b1 + *a1 * *b2 + *a0 * *b3;
    double x_2 = *a2 * b0 + *a1 * *b1 + *a0 * *b2;
    double x_1 = *a1 * b0 + *a0 * *b1;
    double x_0 = *a0 * b0;
    // The results of the operations are assigned to variables with the help of pointers.
    *a3 = x_6;
    *a2 = x_5;
    *a1 = x_4;
    *a0 = x_3;
    *b3 = x_2;
    *b2 = x_1;
    *b1 = x_0;
}