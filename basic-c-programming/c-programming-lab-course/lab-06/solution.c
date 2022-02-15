/*
    CSE 108 - 6
    Name: Berkcan EKICI
    Id: 171044015
*/
#include <stdio.h>
#include <stdlib.h>

/* Function definitions */

// This function creates a certain pattern according
// to a rule.
// It returns an average according to this rule as well.
float average_finder(int row, int col, const int arr[][col])
{
    int total = 0;
    int count = 0;

    for (int i = 0; i < row; ++i)
        for (int k = 0; k < col; ++k)
            if (!((i + k) % 2)) {
                total += arr[i][k];
                ++count;
            }

    return (float)total / count;
}

// This function prints a matrix on the screen
// in a certain order.
void print_matrix(int row, int col, const int arr[][col])
{
    for (int i = 0; i < row; ++i)
        for (int k = 0; k < col; ++k)
            printf("%d%c", arr[i][k], k % col == col - 1 ? '\n' : '\t');
}

// Combines objects of two const char * types in a 
// specific order. It is similar to strcat function in 
// the header file <string.h>
void interview(const char *s1, const char *s2, char *s3)
{
    while (*s1 || *s2) {
        if (*s1)
            *s3++ = *s1++;
        if (*s2)
            *s3++ = *s2++;
    }

    *s3 = '\0';
}

int main()
{
    // For part1:
    // First of all, 2 arrays are created and
    // the contents of these arrays are filled 
    // with certain values.
    printf("Average Finder\n\n");

    int arr1[3][5];
    int arr2[4][9];
    int idx = 1;
    
    for (int i = 0; i < 3; ++i)
        for(int k = 0; k < 5; ++k) {
            arr1[i][k] = 2 * idx * idx - 3; 
            ++idx;
        }

    idx = 1;

    for (int i = 0; i < 4; ++i)
        for (int k = 0; k < 9; ++k) {
            arr2[i][k] = 2 * idx * idx - 3;
            ++idx;
        }

    // Calls are made to functions. The result is
    // calculated and the arrays are printed on the 
    // screen.
    float result_one = average_finder(3, 5, arr1);
    float result_two = average_finder(4, 9, arr2);

    print_matrix(3, 5, arr1);
    printf("\nResult : %.1f\n\n", result_one);

    print_matrix(4, 9, arr2);
    printf("\nResult : %.1f\n", result_two);

    // For part2:
    // Two string literals and one char array are created
    // and these literals and arrayare sent as arguments to 
    // the function.
    char c_arr[100];
    const char *s1 = "berkcanekici";
    const char *s2 = "1234";

    printf("\nFirst string: %s\n", s1);
    printf("Second string: %s\n", s2);
    
    interview(s1, s2, c_arr);
    printf("STRCAT => %s\n", c_arr);
}