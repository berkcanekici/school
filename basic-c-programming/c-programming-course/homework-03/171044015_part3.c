/*##########################################################################*/
/* ­­­­­­­­­                        HW_03_part_3                                     */
/*                         BERKCAN EKICI                                    */
/*                         171044015                                        */
/* ­­­­­­­­­                                                                         */
/* Created on 11/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/*    This program aims to perform AND logical operator on two              */
/*    integers' digits that requested from the user. The integers           */
/*    will work as decimal numbers, but they will considered as             */
/*    binary number. If the numbers do not have the same length or          */
/*    they contain any number other than 0 or 1, the program will           */
/*    print an error message and ask user to enter two new integers         */
/*    until a proper pair will be obtained.                                 */
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
int my_pow(int, int);
int andop(int, int);
int is_binary(int);
int calculate_digit_number(int);

int main()
{
    int num1;
    int num2;
    int flag_digit = 0;
    int flag_binary = 0;

    printf("First Integer:  ");
    scanf("%d", &num1);
    printf("Second Integer: ");
    scanf("%d", &num2);
    // In this do-while loop, the program checks if the entered numbers are in binary format and if their 
    // lengths are the same. If both conditions are true, then the flag_binary and the flag_length's value will 
    // be changed into 1 and the loop ends.
    do
    {
        while (!is_binary(num1) || !is_binary(num2)) {
            printf("Integers should be binary, please enter 2 new integers.\n");
            printf("First Integer:  ");
            scanf("%d", &num1);
            printf("Second Integer: ");
            scanf("%d", &num2);
        }
        while (calculate_digit_number(num1) != calculate_digit_number(num2)) {
            printf("Integers should have the same length, please enter 2 new integers.\n");
            printf("First Integer:  ");
            scanf("%d", &num1);
            printf("Second Integer: ");
            scanf("%d", &num2);
        }
        if (is_binary(num1) == 1 && is_binary(num2) == 1)
            flag_binary = 1;

        if (calculate_digit_number(num1) == calculate_digit_number(num2))
            flag_digit = 1;

    } while (!flag_digit || !flag_binary);
    printf("%d AND %d = %d\n", num1, num2, andop(num1, num2));
}
// This function calculates the length of the sent number.
int calculate_digit_number(int number)
{
    int digit = 0;
    while (number)
    {
        number /= 10;
        digit++;
    }
    return digit;
}
// This function checks if the sent number is in binary format or not.
int is_binary(int number)
{
    int mode;
    while (number) {
        mode = number % 10;
        if (mode != 0 && mode != 1)
            return 0;
        number /= 10;
    }
    return 1;
}
// This function performs the AND operation.
int andop(int num1, int num2)
{
    int digit = calculate_digit_number(num1);
    int mode_num1;
    int mode_num2;
    int result = 0;
    // Dividing numbers to 10^(length-1) to obtain the left-most digits.
    while (digit) {
        mode_num1 = num1 / my_pow(10, digit - 1);
        mode_num2 = num2 / my_pow(10, digit - 1);

        while (mode_num1 != 1 && mode_num1 != 0)
            mode_num1 %= 10;
        while (mode_num2 != 1 && mode_num2 != 0)
            mode_num2 %= 10;
        if (1 == mode_num1 && 1 == mode_num2)
            result += my_pow(10, digit - 1);
        digit--;
    }
    return result;
}
// This function calculates the power raised to the base value.
int my_pow(int base, int exponent)
{
    return exponent == 0 ? 1 : base * my_pow(base, exponent - 1);
}
/*###########################################################################*/
/*                        End of 171044015_part3.c                           */
/*###########################################################################*/