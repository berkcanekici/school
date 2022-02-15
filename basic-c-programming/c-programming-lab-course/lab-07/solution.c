/*
    CSE 108 - 7
    Name: Berkcan EKICI
    Id: 171044015
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declarations */
int check_palindrome(int [], int);
void randomize();
void set_random_array(int *, size_t);
void set_array_user(int *, size_t);
int search_element(int [], int, int, int);
void display_array(const int *, size_t);
float _cos(int, float);

int main()
{
    // Part1:
    // An array is created.
    // This array is filled with numbers received from the user.
    // It is tested with the help of the check_palindrome function.
    // The output is printed on the console.
    printf("PART1:\n");
    int arr_p1[7] = {};

    set_array_user(arr_p1, 7);

    if (check_palindrome(arr_p1, 7))
        printf("Your input is a palindrome\n");
    else
        printf("Your input is not a palindrome\n");
    
    // Part2:
    // An array is created.
    // This array is filled with random numbers.
    // This array is printed on the console.
    // User enters the number wants to search.
    // The output printed on the console.
    printf("\nPART2:\n");
    int arr_p2[20] = {};

    set_random_array(arr_p2, 20);
    printf("Array:\n");
    display_array(arr_p2, 20);

    printf("\nPlease enter a number:\n");
    int rand_num; 
    scanf("%d", &rand_num);

    if (search_element(arr_p2, 0, 19, rand_num))
        printf("Element found.\n");
    else
        printf("Couldn't find element.\n");
    
    // Part3:
    // The numbers n and x are requested from the user.
    // The output printed on the console.
    printf("\nPART3:\n");
    int n;
    float x;

    printf("Please enter the n number:\n");
    scanf("%d", &n);

    printf("Please enter the x number\n");
    scanf("%f", &x);

    printf("cos(%d, %.2f) = %f", n, x, _cos(n, x)); 
}

// This function recursively checks whether the array is
// palindrome or not.
int check_palindrome(int array[], int n)
{
    if (n <= 1)
        return 1;

    if (array[0] != array[n-1])
        return 0;

    return check_palindrome(array + 1, n - 2);
}

// This function is only available for srand function.
void randomize()
{
    srand((unsigned)time(NULL));
}

// Fills the array with randomly.
void set_random_array(int *p, size_t size)
{
    randomize();

    while (size--)
        *p++ = rand() % 100;
}

// Fills the array with numbers received from the user.
void set_array_user(int *p, size_t size)
{
    while (size--) {
        printf("Please enter a number:\n");
        scanf("%d", p++);
    }
}
// Prints an array to the console.
void display_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        if (i && i % 10 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }
}
// This function does recursively search. 
int search_element(int arr[], int low, int high, int input_number)
{
    if (high < low)
        return 0;

    if (arr[low] == input_number ||
        arr[high] == input_number)
        return 1;
        
    return search_element(arr, low + 1, high - 1, input_number);
}
// This function calculates cos in a recursive way. 
float _cos(int n, float x)
{
    if (n < 2)
        return n;
    
    float f = x * x / (2 * (n - 1) * 2 * n);
    
    return (1 - f)  * _cos(n - 1, x) + f * _cos(n - 2, x);
}