/*
    Süper asal nedir?

    Bu sayılara "asal indeksli asal sayılar" (prime indexed primes) da denilmektedir. 
    Tüm asal sayıların 1 değerinden başlayarak indekslendiğini düşünelim:

    1. asal sayı 2
    2. asal sayı 3
    3. asal sayı 5
    4. asal sayı 7
    5. asal sayı 11
    6. asal sayı 13
    7. asal sayı 17

    Eğer bir asal sayının indeksi de (yani kaçıncı asal sayı olduğunu gösteren tamsayı da) 
    asal ise bu asal sayı bir süper asaldır. Örneğin yukarıdaki tabloda yer alan 3 (2 indeksli), 
    5 (3 indeksli), 11 (5 indeksli) ve 17 (7 indeksli) süper asal sayılardır.

    Yazdığınız işlev kodunu aşağıdaki süper asal sayılarla test edebilirsiniz:

    3, 5, 11, 17, 31, 41, 59, 67, 83, 109, 127, 157, 179, 191, 211, 241, 277, 
    283, 331, 353, 367, 401, 431, 461, 509, 547, 563, 587, 599, 617, 709, 739, 
    773, 797, 859, 877, 919, 967, 991

*/

#include <stdio.h>

int is_prime(int);
int is_superprime(int);

int main() 
{
    int ival;

    printf("Enter the number you want to test for Super prime.\n");
    scanf("%d", &ival);
   
    if (!is_prime(ival))
        printf("%d is not a prime number.", ival);
    else
        is_superprime(ival);
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
    for (int i = 7; i * i <= val; ++i)
        if (val % i == 0)
            return 0;
    return 1;
}

int is_superprime(int val) 
{
    int count = 0;

    for (int i = 2; i <= val; ++i)
        if (is_prime(i))
            ++count;
    
    if (is_prime(count))
        printf("%d is a super prime number.", val);
    else
        printf("%d is not a super prime number.", val);
}   
