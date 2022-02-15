/*
    CSE 108 - 2
    Name: Berkcan EKICI
    Id: 171044015
*/

/* Header Files */
#include <stdio.h>
#include <math.h>

/* Preprocessor Macros */
#define    PI    3.14

/* Function declarations */
void start_calculator(void);
void start_standard_calculator(void);
int integer_addition(int, int);
int integer_multiplication(int, int);
int complex_multiplication_real(int, int, int, int);
int complex_multiplication_img(int, int, int, int);
int complex_addition(int, int);
void start_area_perimeter_calculator(void);
double calculate_rectangle(int, int, int);
double calculate_triangle(int, int, int, int);
double calculate_circle(int, int);
void start_temperature_calculator(void);
double fah_to_kel(double);
double kel_to_fah(double);

int main()
{
    /* The program is started */
    start_calculator();
}

/* Which part will be start is taken from the user. */
void start_calculator(void) 
{
    int calculator_type;

    do {
        printf("\nEnter the calculator type\n");
        printf(" 1. Standart Calculator\n");
        printf(" 2. Area&Perimeter Calculator\n");
        printf(" 3. Temperature Calculator\n");
        printf(" 0. Exit\n");
        printf("---------------------------------\n");
        scanf("%d", &calculator_type);

        switch (calculator_type) {
	        case 1:
	            start_standard_calculator();
	            break;
	        case 2:
	            start_area_perimeter_calculator();
	            break;
	        case 3:
	            start_temperature_calculator();
	            break;
	        case 0:
	            printf("Good bye!\n");
	            break;
	        default:
	            break;
        }
    } while (calculator_type != 0);

}

/* The real and imaginary parts of the complex numbers are adding */
int complex_addition(int n1, int n2)
{
    return n1 + n2;
}

/* The real parts of the complex numbers are multiplied */
int complex_multiplication_real(int r1, int i1, int r2, int i2)
{
    return r1 * r2 + i1 * i2 * -1;
}

/* The imagimary parts of the complex numbers are multiplied */
int complex_multiplication_img(int r1, int i1, int r2, int i2)
{
    return r1 *i2 + r2 * i1;
}

/* The integer numbers are adding */
int integer_addition(int a, int b)
{
    return a + b;
}

/* The integer numbers are multiplied */
int integer_multiplication(int a, int b)
{
    return a * b;
}

/* PART 1 FUNCTION */
void start_standard_calculator(void)
{
    int number_type;
    int calculation_type;

    printf("Enter the number type\n");
    printf(" 1. Integer\n");
    printf(" 2. Complex\n");
    printf("---------------------------------\n");
    scanf("%d", &number_type);
    printf("Enter the calculation type\n");
    printf(" 1. Addition\n");
    printf(" 2. Multiplication\n");
    scanf("%d", &calculation_type);

    /* For integer numbers: */
    if (1 == number_type) {
        int num1, num2;
        printf("Please enter the first integer number\n");
        scanf("%d", &num1);
        printf("Please enter the second integer number\n");
        scanf("%d", &num2);

        if (1 == calculation_type)
            printf("Addition of the numbers %d + %d = %d\n", num1, num2, integer_addition(num1, num2));
        else if (2 == calculation_type)
            printf("Multiplication of the numbers %d * %d = %d\n", num1, num2, integer_multiplication(num1, num2));
    }
    /* For complex numbers: */
    else if (2 == number_type) {
        int real1, real2, img1, img2;
        printf("Please enter the first complex number (real part first):\n");
        scanf("%d%d", &real1, &img1);
        printf("Please enter the second complex number (real part first):\n");
        scanf("%d%d", &real2, &img2);

        if (1 == calculation_type) 
            printf("Addition of the numbers = %d + (%di)\n", complex_addition(real1, real2), complex_addition(img1, img2));       
        else if (2 == calculation_type)
            printf("Multiplication of the numbers = %d + (%di)\n", complex_multiplication_real(real1, img1, real2, img2), 
                                                                   complex_multiplication_img(real1, img1, real2, img2));
    }
}

/* Rectangle calculations */
double calculate_rectangle(int choose, int side1, int side2)
{
    if (1 == choose)
        return 2 * (side1 + side2);

    return side1 * side2;
}

/* Triangle calculations */
double calculate_triangle(int choose, int side1, int side2, int side3)
{
    if (1 == choose)
        return (double)side1 + side2 + side3;
    
    double s = (double)(side1 + side2 + side3) / 2;

    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

/* Circle calculations */
double calculate_circle(int choose, int radius)
{
    if (1 == choose)
        return 2 * PI * radius;

    return PI * radius * radius;
}

/* Part 2 function */
void start_area_perimeter_calculator(void) 
{
    int shape_type;

    printf("Enter the shape type\n");
    printf(" 1. Rectangle\n");
    printf(" 2. Triangle\n");
    printf(" 3. Circle\n");
    printf("---------------------------------\n");
    scanf("%d", &shape_type);
    /* For rectangle: */
    if (1 == shape_type) {
        int side1, side2;
        printf("Please enter two sides of rectangle\n");
        scanf("%d%d", &side1, &side2);
        printf(" Perimeter of rectangle = %f\n", calculate_rectangle(1, side1, side2));
        printf(" Area of rectangle = %f\n", calculate_rectangle(2, side1, side2));
    }
    /* For triangle: */
    else if (2 == shape_type) {
        int side1, side2, side3;
        printf("Please enter three sides of triangle\n");
        scanf("%d%d%d", &side1, &side2, &side3);
        printf(" Perimeter of triangle = %f\n", calculate_triangle(1, side1, side2, side3));
        printf(" Area of triangle = %f\n", calculate_triangle(2, side1, side2, side3));
    }
    /* For circle: */
    else {
        int radius;
        printf("Please enter the radius of circle\n");
        scanf("%d", &radius);
        printf("Perimeter of circle = %f\n", calculate_circle(1, radius));
        printf("Area of circle = %f\n", calculate_circle(2, radius));
    }

}

/* Converts fahrenheit to kelvin */
double fah_to_kel(double fah)
{
    return (((double)5 / 9) * (fah - 32)) + 273.15;
}
/* Converts kelvin to fahrenheit */

double kel_to_fah(double kel)
{
    return (((double)9 / 5) * (kel - 273.15)) + 32;
}

/* Part 3 function: */
void start_temperature_calculator(void) 
{
    int temperature_type;

    printf("Enter the calculation type\n");
    printf(" 1. Fahrenheit to Kelvin\n");
    printf(" 2. Kelvin to Fahrenheit\n");
    printf("---------------------------------\n");
    scanf("%d", &temperature_type);
    
    /* For fahrenheit to kelvin: */
    if (1 == temperature_type) {
        int fahrenheit;
        printf("Please enter the temperature in Fahrenheit\n");
        scanf("%d", &fahrenheit);
        printf("\nResult = %f\n", fah_to_kel(fahrenheit));
    }
    /* For kelvin to fahrenheit: */
    else if (2 == temperature_type) {
        int kelvin;
        printf("Please enter the temperature in Fahrenheit\n");
        scanf("%d", &kelvin);
        printf("\nResult = %f\n", kel_to_fah(kelvin));
    }
}