/*
    CSE 108 - 1
    Name: Berkcan EKICI
    Id: 171044015
*/

#include <stdio.h>

/* Preprocessor Macros */
#define ONE_YEAR 365

/* Function declarations */
void trigonometry(int, int, int);
void trigonometry_calculation(int, int, int);
void age(int);
unsigned int age_calculation(int);

int main()
{
    /* Side lengths are taken for trigonometric operations. */
    int a, b, c;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    trigonometry(a, b, c); // The lengths taken are passed to the function as arguments.

    /* Age information is taken and passed as argument to the function. */
    int person_age;
    printf("Your age: ");
    scanf("%d", &person_age);
    age(person_age);
}

/* The task of this function is to perform trigonometric operations and display the results on the screen. */
void trigonometry_calculation(int a, int b, int c)
{
    printf("sinx = %.1f\n", (double)a / c);
    printf("cosx = %.1f\n", (double)b / c);
    printf("tanx = %.2f\n", (double)a / b);
}

/* This function is client code. 
   The task of this function is to call the calculated function.
*/
void trigonometry(int a, int b, int c)
{
    trigonometry_calculation(a, b, c);
}

/* This function is client code. Displays the calculated second value to the user. */
void age(int x) 
{
    printf("You are %u seconds\n", age_calculation(x));
}

/* This function calculates how many seconds a person's age is. */
unsigned int age_calculation(int x)
{
    unsigned int totalSeconds = 0;

    for(int i = 0; i < x; ++i)
        for(int j = 0; j < ONE_YEAR; ++j)
            totalSeconds += 86400;  
        //totalSeconds += 21600; This is for 1 year = 365 days + 6 hours

    return totalSeconds;
}