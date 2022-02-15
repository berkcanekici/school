/*##########################################################################*/
/* ­­­­­­­­­                        HW_03_part_2                                     */
/*                         BERKCAN EKICI                                    */
/*                         171044015                                        */
/* ­­­­­­­­­                                                                         */
/* Created on 11/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/*    This program aims to check every integer if they are prime            */
/*    or not from 2 to N, where N is an integer requested from the user.    */
/*    If the checked number is prime, an information message will be        */
/*    printed on the console. If else, the least divisor of the number      */
/*    will be printed on the console.                                       */
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
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
int isprime(int);
int least_divisor(int);

int main()
{
    int number;

    printf("Please enter an integer: ");
    scanf("%d", &number);
    printf("\n");

    for (int i = 2; i < number; ++i) {
        int flag = isprime(i);
        if (flag)
            printf("%d is a prime number.\n", i);
        else
            printf("%d is not a prime number, it is dividible by %d\n", i, least_divisor(i));
        printf("\n");
    }
}
// This function checks the number, that sent as an argument, 
// is prime or not by using the formula of 1 < x <= √a.
int isprime(int number)
{
    if (0 == number || 1 == number)
        return 0;
    if (number % 2 == 0)
        return number == 2;
    if (number % 3 == 0)
        return number == 3;
    if (number % 5 == 0)
        return number == 5;
    
    for (int i = 7; i * i <= number; i += 2)
        if (number % i == 0)
            return 0;
    return 1;
}
// This function calculates the smallest divisor of a number. 
int least_divisor(int num)
{
    int flag;
    for (int i = num; 2 <= i; --i)
        if (num % i == 0)
            flag = i;
    return flag;
}
/*###########################################################################*/
/*                        End of 171044015_part2.c                           */
/*###########################################################################*/
