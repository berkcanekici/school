/*##########################################################################*/
/* ­­­­­­­­­                       HW_01  ver_1.0                                    */
/*                         BERKCAN EKICI                                    */
/*                         171044015.c                                      */
/* ­­­­­­­­­                                                                         */
/* Created on 21/02/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/*      The program consists of 3 functions. The menu function is not       */
/*      performed. In function 1, root is calculated with the coefficient   */
/*      values received from the user. I created the delta calculation      */
/*      function. The second function is implemented with "Newton Raphson   */
/*      Method". As a result of these processes, real root and false root   */
/*      are obtained. The distance between them is calculated. In the       */
/*      3rd function, there is the nearest divider of a number.             */ 
/*                                                                          */
/*                                                                          */
/* Notes                                                                    */
/* ­­­­­                                                                         */                                 
/*     This file is prepared and compressed in Ubuntu 18.04 LTS.            */
/*     Comments may be seem as corrupted on Windows OS.                     */
/*     Compiled and tested with GCC.                                        */
/*                                                                          */
/*##########################################################################*/

/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                               Includes                                   */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
#include <stdio.h>
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */

int get_delta(int, int, int);
void find_root(void);
void find_newtonian_root(void);
int find_multiple_closest(int, int);

int main() 
{    
    find_root();
    find_newtonian_root();
    
    int mult_1, mult_2;
    printf("Please enter first integer:");
    scanf("%d", &mult_1);
    printf("Please enter second integer:");
    scanf("%d", &mult_2);

    if (!mult_2) 
        printf("The second number cannot be divided by 0.\n");
    else if (find_multiple_closest(mult_1, mult_2) == 0)
        printf("Output> Closest number to %d that is multiple of %d is itself.", mult_1, mult_2); 
    else 
        printf("Output> Closest number to %d that is multiple of %d is %d.\n", mult_1, mult_2, find_multiple_closest(mult_1, mult_2));
    printf("\n");

}
/*Gets number from user and calculates root                                 */
void find_root(void) 
{
    int first_co;
    int second_co;
    int third_co;
    int root_1, root_2;
    
    printf("Please Enter the first coefficient:");
    scanf("%d", &first_co);
    printf("Please Enter the second coefficient:");
    scanf("%d", &second_co);
    printf("Please Enter the third coefficient:");
    scanf("%d", &third_co);
    /*The coefficient of x ^ 2 cannot be 0.                                 */
    if (first_co) {
        /*When outputting to the console, it calculates the status of the   */
        /*signs(+, -) in between.                                           */
        if (second_co < 0 && third_co < 0)
            printf("Output>Your equation %dx^2%dx%d", first_co, second_co, third_co);
        else if (second_co >= 0 && third_co >= 0)
            printf("Output>Your equation %dx^2+%dx+%d", first_co, second_co, third_co);
        else if (second_co < 0 && third_co >= 0)
            printf("Output>Your equation %dx^2%dx+%d", first_co, second_co, third_co);
        else if (second_co >= 0 && third_co < 0)
            printf("Output>Your equation %dx^2+%dx%d", first_co, second_co, third_co);

        int delta = get_delta(first_co, second_co, third_co);
        
        if (delta < 0)
            printf(" does not have any real roots.\n");
        else if (delta == 0) {
            root_1 = ((-second_co + sqrt(delta)) / (2 * first_co));
            printf(" have a real root {%d}\n", root_1);
        }
        else {
            root_1 = ((-second_co + sqrt(delta)) / (2 * first_co));
            root_2 = ((-second_co - sqrt(delta)) / (2 * first_co));
            root_1 > root_2 ? printf(" have real roots {%d, %d}.\n", root_1, root_2) : printf(" have real roots {%d, %d}.\n", root_2, root_1);
        }
        printf("\n");
    }
    else
        printf("The coefficient of x^2 cannot be 0!\n");    
}
/*The operation is performed according to the relationship between the number */
/*and the mode.                                                               */
int find_multiple_closest(int a, int b) 
{
    int mod = a % b;
    
    if (!mod)
        return 0;
    else 
        if (mod < ((double)b / 2))
            return a - mod;
        else if (mod > ((double)b / 2))
            return b - mod + a;
        else if (mod == ((double) b / 2))
            return a + mod; 
}
void find_newtonian_root(void) 
{
    int first_co, second_co, third_co;
    double initial, root_1, root_2, 
    estimated_root, actual_root, result_func, 
    result_derivative, diff;

    printf("Please Enter the first coefficient: ");
    scanf("%d", &first_co);
    printf("Please Enter the second coefficient: ");
    scanf("%d", &second_co);
    printf("Please Enter the third coefficient: ");
    scanf("%d", &third_co);
    printf("Enter the initial: ");
    scanf("%lf", &initial);

    int delta = get_delta(first_co, second_co, third_co);
    root_1 = (double)((-second_co + sqrt(delta)) / (2 * first_co));
    root_2 = (double)((-second_co - sqrt(delta)) / (2 * first_co));
    
    if (root_1 >= root_2)
        actual_root = root_1;
    else
        actual_root = root_2;

    if (second_co < 0 && third_co < 0)
        printf("Output>Your equation %dx^2%dx%d", first_co, second_co, third_co);
    else if (second_co >= 0 && third_co >= 0)
        printf("Output>Your equation %dx^2+%dx+%d", first_co, second_co, third_co);
    else if (second_co < 0 && third_co >= 0)
        printf("Output>Your equation %dx^2%dx+%d", first_co, second_co, third_co);
    else if (second_co >= 0 && third_co < 0)
        printf("Output>Your equation %dx^2+%dx%d", first_co, second_co, third_co);
    printf(" and iterations are\n");
    printf("\nStep\tx\t\tf(x)\t\tDifference\n");
    int i = 0;
    /*The result of the function is calculated, the derivative of the function */
    /*is calculated, the estimated root is calculated, and other operations    */
    /*are performed.                                                           */
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    result_derivative = ((initial*first_co*2) + second_co);
    estimated_root = (initial - (result_func / result_derivative));
    initial = estimated_root;
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    diff = estimated_root - actual_root;
    printf("x%d\t%.4f\t\t%.4f\t\t%.4f\n", ++i, estimated_root, result_func, diff);

    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    result_derivative = ((initial * first_co * 2) + second_co);
    estimated_root = (initial - (result_func / result_derivative));
    initial = estimated_root;
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    diff = estimated_root - actual_root;
    printf("x%d\t%.4f\t\t%.4f\t\t%.4f\n", ++i, estimated_root, result_func, diff);

    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    result_derivative = ((initial * first_co * 2) + second_co);
    estimated_root = (initial - (result_func / result_derivative));
    initial = estimated_root;
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    diff = estimated_root - actual_root;
    printf("x%d\t%.4f\t\t%.4f\t\t%.4f\n", ++i, estimated_root, result_func, diff);

    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    result_derivative = ((initial * first_co * 2) + second_co);
    estimated_root = (initial - (result_func / result_derivative));
    initial = estimated_root;
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    diff = estimated_root - actual_root;
    printf("x%d\t%.4f\t\t%.4f\t\t%.4f\n", ++i, estimated_root, result_func, diff);

    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    result_derivative = ((initial * first_co * 2) + second_co);
    estimated_root = (initial - (result_func / result_derivative));
    initial = estimated_root;
    result_func = (first_co * (initial * initial) + (second_co * initial) + third_co);
    diff = estimated_root - actual_root;
    printf("x%d\t%.4f\t\t%.4f\t\t%.4f\n", ++i, estimated_root, result_func, diff);
    printf("\n");
}

int get_delta(int a, int b, int c) 
{
    return b * b - 4 * a * c;
}
/*###########################################################################*/
/*                           End of 171044015.c                              */
/*###########################################################################*/
