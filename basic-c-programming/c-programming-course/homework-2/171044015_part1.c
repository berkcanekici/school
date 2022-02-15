/*##########################################################################*/
/* ­­­­­­­­­                        HW_02_part_1                                     */
/*                         BERKCAN EKICI                                    */
/*                         171044015                                        */
/* ­­­­­­­­­                                                                         */
/* Created on 04/03/2020 by Berkcan EKICI                                   */
/*                                                                          */
/* Description                                                              */
/* ­­­­­­­­­­­                                                                         */
/*    This code is the first part of the assignment. The user is asked      */
/*    for 3 edges and it is questioned whether the sides create a triangle. */
/*    If they form a triangle, the function outputs the triangle's type     */
/*    to the screen.                                                        */
/*                                                                          */
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
#include <math.h>
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
/*                         Function Prototypes                              */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­                                                                          */
int draw_triangle(int, int, int);
void type_triangle(int, int, int);
int perimeter_triangle(int, int, int);
double area_triangle(int, int, int, int);

int main() 
{
    int side1;
    int side2;
    int side3;
    
    printf("Please enter the side1:");
    scanf("%d", &side1);
    printf("Please enter the side2:");
    scanf("%d", &side2);
    printf("Please enter the side3:");
    scanf("%d", &side3);
    printf("\n");
    /* In this section, the circumference of the triangle is calculated.     */
    int perimeter = perimeter_triangle(side1, side2, side3);
    /* If the triangle can be drawn, it calls other functions.               */
    if (draw_triangle(side1, side2, side3)) {
        printf("\"According to the triangle inequality theorem, this triangle can be drawn.\"\n");
        type_triangle(side1, side2, side3);
        printf("The perimeter is triangle %d\n", perimeter);
        printf("The area of triangle: %f\n", area_triangle(side1, side2, side3, perimeter));
    }
    else
        printf("\"According to the triangle inequality theorem, this triangle cannot be drawn.\"\n");
}
/* Checks whether it is a triangle.                                         */
int draw_triangle(int side1, int side2, int side3) 
{
    if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) 
        return 1; 
    return 0;    
}
/* Controls the type of the triangle.                                       */
void type_triangle(int side1, int side2, int side3) 
{
    if(side1 == side2 && side2 == side3) 
        printf("It is a Equilateral Triangle.\n");
    else if((side1 == side2 || side2 == side3 || side3 == side1) && !(side1 == side2 && side1 == side3))
        printf("It is a Isosceles Triangle.\n");
    else
        printf("It is a Scalar Triangle.\n");
}
/* Calculates the circumference of the triangle.                            */
int perimeter_triangle(int side1, int side2, int side3) 
{
    return side1 + side2 + side3;
}
/* Calculates the area of the triangle.                                     */
double area_triangle(int side1, int side2, int side3, int perimeter) 
{
    double p = perimeter / 2.;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
