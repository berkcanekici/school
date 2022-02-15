/*##########################################################################*/
/* ­­­­­­­­­                        HW_03_part_1                                     */
/*                         BERKCAN EKICI                                    */
/*                         171044015                                        */
/* ­­­­­­­­­                                                                         */
/* Created on 11/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/*    This program aims to calculate the sum or multiplication of even      */
/*    or odd numbers, due to user's selection, between the range of [1,N],  */
/*    where N is an integer requested from the user.                        */
/*                                                                          */
/*                                                                          */
/* Notes                                                                    */
/* ­­­­­                                                                         */
/*    This file is prepared and compressed in Ubuntu 18.04 LTS.             */
/*    Comments may be seem as corrupted on Windows OS.                      */
/*    Compiled and tested with GCC.                                         */
/*                                                                          */
/*##########################################################################*/

/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                               Includes                                   */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */ 
#include <stdio.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                          Preprocessor Macros                             */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
#define    SUM    0
#define    MULT   1
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
int sum(int, int);
int mult(int, int);

int main()
{
    int number;
    int op_flag;
    int odd_even_flag;

    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Please enter '0' for sum, '1' for multiplication\n");
    scanf("%d", &op_flag);
    printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
    scanf("%d", &odd_even_flag);
    /* If the operation flag's value is different from 0 or 1, an error message will be printed on the console and the program ends. */
    if (op_flag < 0 || 1 < op_flag) {
        printf("Unsupported operation.\n");
        return 1;
    }
    /* If the user enters enters a number other than 0 or 1, an error message will be printed on the console and program ends. */
    if (odd_even_flag < 0 || 1 < odd_even_flag) {
        printf("Invalid value for odd/even selection.\n");
        return 1;
    }
    /* In this switch-case structure, the program calls the propriate function due to the value of operation flag. */
    switch (op_flag) {
    case SUM:
        sum(number, odd_even_flag);
        break;
    case MULT:
        mult(number, odd_even_flag);
        break;
    default:
        break;
    }
}
/* This function performs the addition operation. */
int sum(int n, int flag)
{
    int sum = 0;

    if (flag)
        for (int i = 1; i <= n; i += 2) { 
            /* This if condition is to avoid the plus sign after the last term. */
            if (i == n - 1 || i == n) {
                sum += i;
                printf("%d = %d\n", i, sum);
                break;
            }
            sum += i;
            printf("%d + ", i);
        }
    else
        for (int i = 2; i <= n; i += 2) { 
            /* This if condition is to avoid the plus sign after the last term. */
            if (i == n || i == n - 1) {
                sum += i;
                printf("%d = %d\n", i, sum);
                break;
            }
            sum += i;
            printf("%d + ", i);
        }
}
/* This function performs the multiplication operation. */
int mult(int n, int flag)
{
    int sum = 1;

    if (flag)
        for (int i = 1; i <= n; i += 2) { 
            /* This if condition is to avoid the cross sign after the last term. */
            if (i == n - 1 || i == n) {
                sum *= i;
                printf("%d = %d\n", i, sum);
                break;
            }
            sum *= i;
            printf("%d * ", i);
        }
    else 
        for (int i = 2; i <= n; i += 2) { 
            /* This if condition is to avoid the cross sign after the last term. */
            if (i == n - 1 || i == n) {
                sum *= i;
                printf("%d = %d\n", i, sum);
                break;
            }
            sum *= i;
            printf("%d * ", i);
        }
}
/*###########################################################################*/
/*                        End of 171044015_part1.c                           */
/*###########################################################################*/
