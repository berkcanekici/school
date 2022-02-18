/*
    Bir int diziyi qsort fonksiyonuyla ciftler basta buyukten kucuge, tekler sonda
    buyukten kucuge siralayiniz.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define asize(x) (sizeof(x) / sizeof(x[0]))

void swap(int *, int *);
void bubble_sort(int *, size_t);
void randomize(void);
void display_array(int *, size_t);
void set_random_array(int *, size_t);
int icmp(const void *vp1, const void *vp2);

int main()
{
    int a[SIZE];
    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    qsort(a, SIZE, sizeof(*a), icmp);
    printf("\n\n\n");
    display_array(a, SIZE);
}
void randomize()
{
    srand((unsigned)time(0));
}
void display_array(int *pa, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%3d%c", pa[i], i % 20 == 19 ? '\n' : ' ');
}
void set_random_array(int *pa, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        pa[i] = rand() % 100;
}
int icmp(const void *vp1, const void *vp2)
{
    if ((*(const int *)vp1 % 2 == 1 && *(const int *)vp2 % 2 == 0) || ((*(const int *)vp1 % 2 == *(const int *)vp2 % 2 ) && (*(const int*)vp1 < *(const int *)vp2)))
        return 1;
    return 0;
}
void swap(int *pa1, int *pa2) {
    int temp = *pa1;
    *pa1 = *pa2;
    *pa2 = temp;
}
