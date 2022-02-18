/*
    Basamaksal kök (Digital root) nedir:
    Bir tamsayının basamaksal kökü tüm basamaklarının toplanması ile elde edilen tamsayıdır. 
    Basamakları toplama, tek basamaklı bir sayı elde edilene kadar sürdürülür. 
    Örneğin 34879 sayısının basamaksal kökü 4'tür:

    34879 -> 3 + 4 + 8 + 7 + 9 = 31
    31 -> 3 + 1 = 4
*/

#include <stdio.h>

int get_digital_root(int);
int sum_digits(int);

int main() 
{
    int val;
    
    printf("Please enter the number you want to calculate:\n");
    scanf("%d", &val);
    printf("Digital root of %d = %d\n", val, get_digital_root(val));
}

int get_digital_root(int val) 
{
    int root = sum_digits(val);

    while( root >= 10)
        root = sum_digits(root);
    
    return root;
}
int sum_digits(int val) 
{
    int sum = 0;

    while (val != 0) {
        sum += val % 10;
        val /= 10;
    }

    return sum;
}