/*##########################################################################*/
/* ­­­­­­­­­                        HW_02  part_3                                    */
/*                         BERKCAN EKICI                                    */
/*                           171044015                                      */
/* ­­­­­­­­­                                                                         */
/* Created on 04/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/*    This program is a currency converter. It requires the amount of money ­­­­­­­­­­­*/
/*    that the user has and the currency of the money. Then due to the      */
/*    currency choice, it convert the first currency to the second one.     */
/*                                                                          */
/* Notes                                                                    */
/* ­­­­­                                                                         */
/*    This file is prepared and compressed in Ubuntu 18.04 LTS.             */
/*    Comments may be seem as corrupted on Windows OS.                      */
/*    Compiled and tested with GCC.                                         */
/*                                                                          */
/*##########################################################################*/
#include <stdio.h>
#define    EURO    6.69
#define    DOLLAR  6.14

int main() 
{
    int select, second_select;
    int flag = 1;
    double amount;
    
    printf("***** Welcome to BEKICI Exchange Office *****\n\n");
    printf("Enter your amount:\n");
    scanf("%lf", &amount);
    printf("Please select your currency\n"
           "1. Turkish Lira\n"
           "2. Euro\n"
           "3. Dollar\n");
    scanf("%d", &select);
    
    switch (select) {
        case 1: printf("You have %f Turkish Liras\n", amount); break;
        case 2: printf("You have %f EURO\n", amount); break;
        case 3: printf("You have %f DOLLAR\n", amount); break;
        default: printf("Your selection is invalid.\n"); flag = 0; break; 
    }

    if (!flag) /* If the user's entry is invalid, program ends. */ 
        return 1;

    printf("Choose which currency you want to convert\n");
    scanf("%d", &second_select);
    
    /* This conditions are to make the right calculations. */
    if (second_select > 3 || second_select < 1) {
        printf("Your selection is invalid.\n");
        return 1;
    }
    if (1 == select && 1 == second_select) {
        amount *= 1;
        printf("You have %f TL\n", amount);
    }
    if (1 == select && 2 == second_select) {
        amount /= EURO;
        printf("You have %f EURO\n", amount);
    }
    if (1 == select && 3 == second_select) {
        amount /= DOLLAR;
        printf("You have %f DOLLAR\n", amount);
    }
    if (2 == select && 1 == second_select) {
        amount *= EURO;
        printf("You have %f TL\n", amount);
    }
    if (2 == select && 2 == second_select) {
        amount *= 1;
        printf("You have %f EURO\n", amount);
    }
    if (2 == select && 3 ==  second_select) {
        amount *= (EURO / DOLLAR);
        printf("You have %f DOLLAR\n", amount);
    }
    if (3 == select && 1 == second_select) {
        amount *= DOLLAR;
        printf("You have %f TL\n", amount);
    }
    if (3 == select && 2 == second_select) {
        amount *= (DOLLAR / EURO);
        printf("You have %f EURO", amount);
    }
    if (3 == select && 3 == second_select) {
        amount *= 1;
        printf("You have %f DOLLAR\n", amount);
    }
    printf("\n");
}
