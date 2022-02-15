/*
    CSE 108 - 3
    Name: Berkcan EKICI
    Id: 171044015
*/

#include <stdio.h>
#include <stdlib.h> // for abs() function

/* Function declarations */
int find_max_distance(int);
void find_odd_average();

int main()
{    
    printf("Max dist. between two consecutive nums: %d\n", find_max_distance(5)); // Part 1
    find_odd_average(); // Part 2
}

// This function calculates the largest difference between consecutive integers.
int find_max_distance(int num_inputs)
{
    int num; // input variable
    int num1 = 0; // first number
    int num2 = 0; // second number
    int maxDiff = 0; // maximum difference number
    int newDiff = 0; // new difference number

    // A loop iteration the value received as an argument:
    for (int i = 0; i < num_inputs; ++i) {
        // The values are taken from the user.
        printf("%d: ", i + 1);
        scanf("%d", &num);
        // No action is taken in the first iteration.
        if (i == 0)
            num1 = num;
        
        // The maximum difference is calculated in later iterations.
        if (i != 0 && i % 2 == 0) {
            num1 = num;
            newDiff = abs(num1 - num2);
        } 
        else {
            num2 = num;
            newDiff = abs(num2 - num1);
        }

        if (newDiff > maxDiff)
            maxDiff = newDiff;
        
    }

    return maxDiff;
}
// This function calculates the average of odd numbers.
void find_odd_average()
{
    int number;
    int total_odd_numbers = 0;
    int count_odd_numbers = 0;
    
    // This loop that runs until the user enter -1:
    for (int i = 0; number != -1; ++i) {
        printf("%d: ", i + 1);
        scanf("%d", &number);
        // These operations are done for odd numbers:
        if (number != -1 && number % 2) {
            total_odd_numbers += number;
            ++count_odd_numbers;
        }
    }
    
    if (count_odd_numbers != 0)
        printf("Average of odd numbers: %.2f\n", (double)total_odd_numbers / count_odd_numbers);
    else
        printf("There isn't any odd number.\n");
}