
#include <stdio.h>
#include <stdint.h>

int F_long_num(long num);
int F_double_num(double num);

int main()
{
    long num_long;
    printf("Введите число в формате LONG - ");
    scanf("%ld", &num_long);
    getchar();
    printf("Кол-во единичных битов в LONG - %d", F_long_num(num_long));

    double num_double;
    printf("\n\nВведите число в формате DOUBLE - ");
    scanf("%lf", &num_double);
    getchar();
    printf("\nКол-во единичных битов в DOUBLE - %d", F_double_num(num_double));

    return 0;
}

int F_long_num(long num)
{
    int res = 0;
    while (num != 0)
    {
        res += num & 1;
        num >>=1;
    }
    return res;
}

int F_double_num(double num)
{
    uint64_t num_p = *(uint64_t*)&num;
    int res = 0;
    while (num_p != 0)
    {
        res += num_p & 1;
        num_p >>=1;
    }
    return res;
}