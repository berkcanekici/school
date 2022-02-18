/*
    Collatz sanısı (Collatz conjecture)
    1937 yılında Lothar Collatz sıfırdan büyük her tamsayı için aşağıdaki problemi ortaya koydu:
    n bir tamsayı olmak üzere her yeni n değeri için aşağıdaki kurallar uygulanacak n, 1 değerine 
    eşit ise işlemler sonlandırılıyor. n çift ise yeni n değeri olarak n / 2 alınıyor. n tek ise 
    yeni n değeri olarak 3 * n + 1 değeri alınıyor.

    Collatz sanısı matematikçilerin tüm çabalarına karşın halen kanıtlanmış değildir.
*/

#include <stdio.h>

unsigned int display_collatz(unsigned long long val);

int main() 
{
    unsigned long long uval;

    printf("Please enter a number.\n");
    scanf("%llu", &uval);

    unsigned count = display_collatz(uval);
    printf("There are total of %u numbers in the series.", count);
}

unsigned int display_collatz(unsigned long long val) 
{
    unsigned int count = 0u;

    for (;;) {
        ++count;
        
        count % 20 ? printf("%llu ", val) : printf("\n");
        
        if (val == 1)
            break;
        if (val % 2)
            val = 3 * val + 1;
        else
            val /= 2;
    }

    printf("\n");
    
    return count;
}
