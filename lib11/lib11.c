#include <stdio.h>
#include "lib11_fun.c"

int main()
{
    printf("Сумма: %.2f\n", sum_f(3, 2.5, -0.5, 3.0));
    printf("Максимальное значение: %.2f\n", max_f(3, 2.5, -0.5, 3.0));
    printf("Минимальное значение: %.2f\n", min_f(3, 2.5, -0.5, 3.0));
    printf("Среднее значение: %.2f", arith_f(3, 2.5, -0.5, 3.0));
    return 0;
}
