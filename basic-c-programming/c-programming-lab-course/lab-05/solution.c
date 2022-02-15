/*
    CSE 108 - 5
    Name: Berkcan EKICI
    Id: 171044015
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declarations */
void expression0(int, int *);
void expression1(int, int *);
void expression2(int, int *);
void calculation(int *, int);
void addition(void(*)(int, int *), int *, int);
void print_result(const int *, int);
void randomize();
void createArray(int(*)[10]);
void displayArray(const int(*)[10], int);
void searchArray(const int(*)[10], int);

int main()
{
    // Part 1:    
    int result_array[3] = { 0 };
    int n;

    printf("n: ");
    scanf("%d", &n);

    calculation(result_array, n);  // Calculate processes
    print_result(result_array, 3); // Results print to console.

    // Part 2:
    int arr[10][10] = { 0 };

    randomize();                   // Only srand function to change the seeds.
    createArray(arr);              // Array filled.
    displayArray(arr, 10);         // Array print to console.

    for (;;)                       // A loop that the until the wrong input arrives.
        searchArray(arr, 10); 
}

// Processing is done for every x value.
void expression0(int x, int *result)
{
    *result += x * x + 5;   
}

// Processing is done for every x value.
void expression1(int x, int *result)
{
    *result += 2 * x + 1;
}

// Processing is done for every x value.
void expression2(int x, int *result)
{
    *result += x * x;  
}

// By using the function address, we process all x's.
void addition(void (*func)(int, int *), int *sum, int n)
{
    for (int i = 0; i <= n; ++i)
        func(i, sum);
}

// The result of the three operations is assigned to the resulting
// array as an argument.
void calculation(int *sumArray, int n)
{
    int result_one = 0;
    int result_two = 0;
    int result_three = 0;
    
    addition(expression0, &result_one, n);
    addition(expression1, &result_two, n);
    addition(expression2, &result_three, n);
    
    sumArray[0] = result_one;
    sumArray[1] = result_two;
    sumArray[2] = result_three;
}

// The expressions results are printed to the console.
void print_result(const int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("Sum of expression%d = %d\n", i, arr[i]);
    printf("\n");
}

// Use srand function.
void randomize()
{
    srand((unsigned)time(NULL));
}

// Elements are assigned to the inside of the array.
void createArray(int (*array)[10])
{
    for (int i = 0; i < 10; ++i)
        for (int k = 0; k < 10; ++k)
            array[i][k] = rand() % 90 + 10;
}

// The array elements are printed the console.
void displayArray(const int (*arr)[10], int size)
{
    printf("Matrix:\n\n");

    for (int i = 0; i < size; ++i)
        for (int k = 0; k < size; ++k)
            printf("%d%c", arr[i][k], k == size - 1 ? '\n' : ' ');
    printf("\n");
}

// Checks for element int any row and column.
// If an incorrect row or column is entered, the
// program is terminated.
void searchArray(const int (*arr)[10], int size)
{
    int row, col;

    printf("Which element of the matrix do you want to reach?\n");

    printf("i: ");
    scanf("%d", &row);

    printf("j: ");
    scanf("%d", &col);

    if (row < 0 || col < 0 || size <= row || size <= col) {
        printf("Invalid input. Terminating...\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; ++i)
        for (int k = 0; k < size; ++k)
            if (i == row && k == col)
                printf("%d. row %d. column of the matrix is %d\n\n\n", i, k, arr[i][k]);
}