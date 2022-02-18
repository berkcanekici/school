/*
    Tüm zamanların en ilginç matematikçilerinden biri olan Ramanujan hastanedeyken 
    ünlü matematikçi Hardy onu hastanede ziyarete gider. Hardy gelirken bindiği taksinin 
    plaka numarasının ilginç olmayan bir sayı olan 1729 olduğunu söyler. Ramanujan buna 
    itiraz eder ve 1729 sayısının iki pozitif kübün toplamı olarak, iki değişik şekilde 
    yazılabilecek en küçük sayı olduğunu açıklar:

    1729 = 9^3 + 10^3 = 1^3 + 12^3
    N bir pozitif tamsayı ve a, b, c, d birbirinden farklı tamsayılar olmak üzere eğer

    N = a^3 + b^3 = c^3 + d^3
    eşitliğini sağlayacak a, b, c ve d tamsayıları var ise N bir Hardy-Ramanujan sayısıdır. 
    Örneğin 1729 bir Hardy-Ramanujan sayısıdır.

    Bir C kodu yazarak 100000'den küçük olan tüm Hardy-Ramanujan sayılarını bulunuz.
*/

#include <stdio.h>

#define SIZE 100000

int cube(int);

int main() 
{
    int count = 0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 1; cube(j) <= i; ++j)
            for (int k = j; cube(k) + cube(j) <= i; ++k)
                if (cube(j) + cube(k) == i)
                    count++;
        if (count == 2)
            printf("%d\n", i);
        count = 0;
    }
}

int cube(int n) 
{
    return n * n * n;
}