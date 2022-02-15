/*##########################################################################*/
/* ­­­­­­­­­                        HW_02  part_2                                    */
/*                         BERKCAN EKICI                                    */
/*                           171044015                                      */
/* ­­­­­­­­­                                                                         */
/* Created on 04/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/*    This program aims to find the digit number of an integer that ­­­­­­­­­­­        */
/*    entered by user. Then consider the number written in 100 times        */
/*    side by side. Due to an index number, the program find the number     */
/*    of that index in the written format.                                  */
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
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
int number_length(int);
int find_digit(int, int);

int main()
{
    int number;
    int step;
    
    printf("Enter a number (maximum 6 digits):\n");
    scanf("%d", &number);
    
    printf("Your number has %d digits.\n\n", number_length(number));
    printf("When your number is written 100 times next to each other"
           ", which digit of this number would you like to see? :");
    scanf("%d", &step);
    /*If the value of step is more than 100*digit's number, the program ends.*/
    if (number_length(number) * 100 < step) {
            printf("Basamak sayisini gectiniz.\n");
            return 1;
    }
    printf("%d.th digit of the big number sequence: %d\n", step, find_digit(number, step));
    return 0;
}
/* This function calculates digit's value.                                  */
int number_length(int number)
{
    return number == 0 ? 1 : (int)log10(number) + 1;
}
/* This function find the number of the index which is 100*digit's number   */           
int find_digit(int number, int index)
{
    int digit = number_length(number);
    int mode = index % digit;
    /* If mode is 0, digit assigned to mode.                                */
    if (!mode)
        mode += digit;
    /* This statement calculates new number.                                */
    index = number / (int)pow(10, digit - mode);
    /* This statement calculates last digit of number.                      */
    index %= 10;

    return index;
}


