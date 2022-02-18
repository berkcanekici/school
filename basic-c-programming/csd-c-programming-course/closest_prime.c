/*
    Kendisine gönderien tamsayıdan daha küçük ilk asal sayıyı bulan closest_prime isimli işlevi tanımlayınız:
    İşlevin geri dönüş değeri value değerinden küçük en büyük asal sayı olacaktır.
    Eğer böyle bir asal sayı yok ise işlev hata değeri olarak -1 değerini döndürür.

*/

#include <stdio.h>

int closest_prime(int);
int isprime(int);

int main() 
{
    int a[10] = {1810, 2678, 8887, 13452, 16982, 21777, 29016, 33010, 36876, 42011};
    int b[10] = {1801, 2677, 8867, 13451, 16981, 21773, 29009, 32999, 36871, 41999};
    int k;

    for (k = 0; k < 10; ++k)
        if (closest_prime(a[k]) != b[k]) {
            printf("Wrong solution.\n");
            return 0;
        }

    printf("Correct solution.\n");
    return 0;
}

int closest_prime(int number) 
{
    int prime;

    if(number < 2)
        return -1; 
    
    for (int i = 2; i < number; ++i) 
        if (isprime(i))
            prime = i;

    return prime;
}
int isprime(int number) 
{
    if(number == 0 || number == 1)
        return 0;

    if(number % 2 == 0)
        return 2 == number;

    if(number % 3 == 0)
        return 3 == number;

    if (number % 5 == 0)
        return 5 == number;

    for (int i = 7; i * i <= number; ++i)
        if (number % i == 0)
            return 0;
    
    return 1;
}   
