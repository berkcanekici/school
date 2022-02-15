/*
    CSE 108 - 8
    Name: Berkcan EKICI
    Id: 171044015
*/
#include <stdio.h>
#include <math.h>
#define    MAX    3

struct matrix {
    double arr[MAX][MAX];
    double determinant;
};

struct vector {
    double x;
    double y;
    double z;
};

struct third_order_polynomial {
    double a, b, c, d;
};

struct polynomial {
    double x_6, x_5, x_4;
    double x_3, x_2, x_1;
    double constant;
};

void print_matrix(struct matrix);
void inverse_matrix(struct matrix *, struct matrix *);
void determinant_of_matrix(struct matrix *);
double find_orthogonal(struct vector, struct vector, struct vector *);
struct polynomial get_integral(struct third_order_polynomial, struct third_order_polynomial, int, int);

int main()
{
    struct matrix my_matrix;
    struct vector vec_1;
    struct vector vec_2;
    struct vector vec_3;
    
    /*
    If these are not defined, an error will be received.    
    vec_1.x = 
    vec_1.y = 
    vec_1.z = 
    vec_2.x = 
    vec_2.y = 
    vec_3.z = 
    */

    print_matrix(my_matrix);
    
    double dval = find_orthogonal(vec_1, vec_2, &vec_3);
    
    printf("Vector orthogonal: %f", find_orthogonal(vec_1, vec_2, &vec_3));
}

void print_matrix(struct matrix my_matrix)
{
    double dval;
    int count = 0;

    for (int i = 0; i < MAX; ++i) {
        for (int k = 0; k < MAX; ++k) {
            printf("Please enter %d. number: ", count + 1);
            scanf("%lf", &dval);
            my_matrix.arr[i][k] = dval;
        }
    }

    for (int i = 0; i < MAX; ++i) {
        for (int k = 0; k < MAX; ++k) {
            printf("%.4f%c", my_matrix.arr[i][k], k % 3 == 2 ? '\n' : '\t');
        }
    }
}

void inverse_matrix(struct matrix *initial_matrix, struct matrix *inverted_matrix)
{
    determinant_of_matrix(initial_matrix);

    if (0. == initial_matrix->determinant) {
        printf("Determinant 0");
        return;
    }

    inverted_matrix->arr[0][0] = initial_matrix->arr[1][1] * initial_matrix->arr[2][2] -
                                 initial_matrix->arr[2][1] * initial_matrix->arr[2][2];
    inverted_matrix->arr[0][1] = (initial_matrix->arr[1][0] * initial_matrix->arr[2][2] -
                                 initial_matrix->arr[2][0] * initial_matrix->arr[1][2]) * -1;
    inverted_matrix->arr[0][2] = initial_matrix->arr[1][0] * initial_matrix->arr[2][1] -
                                 initial_matrix->arr[2][0] * initial_matrix->arr[2][1];
    inverted_matrix->arr[1][0] = (initial_matrix->arr[0][1] * initial_matrix->arr[2][2] -
                                 initial_matrix->arr[2][1] * initial_matrix->arr[0][2]) * -1;
    inverted_matrix->arr[1][1] = initial_matrix->arr[0][0] * initial_matrix->arr[2][2] -
                                 initial_matrix->arr[1][2] * initial_matrix->arr[2][0];
    inverted_matrix->arr[1][2] = (initial_matrix->arr[0][0] * initial_matrix->arr[2][1] -
                                 initial_matrix->arr[2][0] * initial_matrix->arr[0][1]) * -1;
    inverted_matrix->arr[2][0] = initial_matrix->arr[0][1] * initial_matrix->arr[1][2] -
                                 initial_matrix->arr[1][1] * initial_matrix->arr[0][2];
    inverted_matrix->arr[2][1] = (initial_matrix->arr[0][0] * initial_matrix->arr[1][2] -
                                 initial_matrix->arr[0][2] * initial_matrix->arr[1][0]) * -1;
    inverted_matrix->arr[2][2] = initial_matrix->arr[0][0] * initial_matrix->arr[1][1] -
                                 initial_matrix->arr[0][1] * initial_matrix->arr[1][0];
    determinant_of_matrix(inverted_matrix);
}

void determinant_of_matrix(struct matrix *initial_matrix)
{
    double first = initial_matrix->arr[0][0] * (initial_matrix->arr[1][1] * initial_matrix->arr[2][2] -
                                                initial_matrix->arr[2][1] * initial_matrix->arr[1][2]);
    double second = initial_matrix->arr[0][1] * (initial_matrix->arr[1][0] * initial_matrix->arr[2][2] -
                                                 initial_matrix->arr[2][0] * initial_matrix->arr[1][2]);
    double third = initial_matrix->arr[0][2] * (initial_matrix->arr[1][0] * initial_matrix->arr[2][1] -
                                                 initial_matrix->arr[1][1] * initial_matrix->arr[2][0]);

    initial_matrix->determinant = first - second + third;
}
double find_orthogonal(struct vector vec_1, struct vector vec_2, struct vector *output_vec)
{
    /*
    double first = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    double second = (vec_1.x * vec_2.z - vec_1.z * vec_2.x) * -1;
    double third = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
    return first + second + third;
    */

   double numerator = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
   double a_square = sqrt(pow(vec_1.x, 2) + pow(vec_1.y, 2) + pow(vec_1.z, 2));
   double b_square = sqrt(pow(vec_2.x, 2) + pow(vec_2.y, 2) + pow(vec_2.z, 2));

   return acos(numerator / (a_square * b_square));
}

struct polynomial get_integral(struct third_order_polynomial p1, struct third_order_polynomial p2, int a, int b)
{
    struct polynomial new_poly;

    new_poly.x_6 = p1.a * p2.a;
    new_poly.x_5 = p1.a * p2.b + p2.a * p1.b;
    new_poly.x_4 = p1.a * p2.c + p1.b * p2.b + p1.c + p2.a;
    new_poly.x_3 = p1.a * p2.d + p2.a * p1.d;
    new_poly.x_2 = p1.b * p2.d + p2.b * p1.d + p1.c + p2.c;
    new_poly.x_1 = p1.c * p2.c + p1.c * p2.d + p2.c * p1.d;
    new_poly.constant = p1.d * p2.d;

    // ...
}
