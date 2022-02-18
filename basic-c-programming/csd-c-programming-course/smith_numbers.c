/*
    1'den büyük asal olmayan bir tamsayının rakamlarının toplamı, 
    sayı asal çarpanlarına ayrılarak yazıldığında bu yazımda yer alan 
    tüm asal sayıların rakamlarının toplamına eşit ise bu sayı bir 
    Smith Sayısı denir.

    Örneğin:

    728 = 2 * 2 * 2 * 7 * 13  
    7 + 2 + 8 = 2 + 2 + 2 + 7 + 1 + 3
    olduğundan 728 bir Smith sayısıdır.

    Peki neden bu sayılara Smith sayıları deniyor. Lehigh Universitesi*'nden
    Albert Wilansky kayın biraderi Harold Smith'in telefon numarasının bu 
    özelliğe sahip olduğunu fark edince bu tür sayılara Smith sayısı demiş. 
    (WikiPedia‘nın yalancısıyım) Kayınço’nun numarası 493 7775.

    493 7775 = 3 × 5 × 5 × 65837, 
    4 + 9 + 3 + 7 + 7 + 7 + 5 = 42
    3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42
    
    1000'den küçük Smith sayıları şunlardır:
    4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346,
    355, 378, 382, 391, 438, 454, 483, 517,526, 535, 562, 576,
    588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 
    729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985
*/
#include <stdio.h>
#define SIZE 1000

int is_prime(int);
int sum_digits(int);
int sum_prime(int);

int main() 
{
    for (int i = 1; i < SIZE; ++i)
        if (!is_prime(i) && (sum_digits(i) == sum_prime(i))) 
            printf("%d, ", i);                              
    printf("\n");
}

int is_prime(int val) 
{
    if (val == 0 || val == 1)
        return 0;
    if (val % 2 == 0)
        return val == 2;
    if (val % 3 == 0)
        return val == 3;
    if (val % 5 == 0)
        return val == 5;
    for (int i = 7; i*i <= val; ++i)
        if (val % i == 0)
            return 0;
    return 1;
}

int sum_digits(int val) 
{
    int sum = 0;

    while (val) {
        sum += val % 10;
        val /= 10;
    }

    return sum;
}

int sum_prime(int val) 
{
    int prime = 2;
    int sum = 0;

    while (1 != val) {
        if (val % prime == 0)    
            if (10 < prime && is_prime(prime)) { 
                sum += sum_digits(prime);       
                val /= prime;
            }
            else {  
            	sum += prime;
            	val /= prime;
            }
        else        
            prime++;        
    }    
    
    return sum;
}
