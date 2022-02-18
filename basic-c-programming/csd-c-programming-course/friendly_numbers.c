/*
    x ve y pozitif tamsayılar olmak üzere, eğer x sayısının 
    çarpanları toplamı y sayısına, ve aynı zamanda y sayısının 
    çarpanları toplamı x sayısına eşit ise, bu sayılar “arkadaştır”. 
    Örneğin 220 ve 284 arkadaş sayılardır:
    220 => 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284
    284 => 1 + 2 + 4 + 71 + 142 = 220
*/

#include <stdio.h>
int are_friends(int, int);

int main() 
{
    int number1, number2;

    printf("Programa hosgeldiniz.\n");
    printf("Lutfen arkadas sayi oldugunu dusundugunuz 2 sayi giriniz.\n");
    scanf("%d%d", &number1, &number2);

    if (!are_friends(number1, number2))
        printf("Bu iki sayi arkadastir.\n");
    else
        printf("Bu iki sayi arkadas degildir.\n");
}

int are_friends(int number1, int number2) 
{
    int count1 = 0, count2 = 0;
    
    for (int i = 1 ; i < number1; ++i)
        if (number1 % i == 0)
            count1 += i;
    for (int i = 1; i < number2; ++i)
        if (number2 % i == 0)
            count2 += i;
    
    if (count1 == number2 && count2 == number1)
        return 0;
           
    return 1;
}

